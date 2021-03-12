#include "include/Canvi.hpp"

using namespace sf;

const unsigned MAX_POINTS = 30000;
const unsigned WINDOW_WIDTH = 800;
const unsigned WINDOW_HEIGHT = 800;

void main_drawer(X_n &complex_points)
{
    RenderWindow window(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), 
                        "Fourier Visualizer",
                        Style::Close);
    VertexArray points(Points, MAX_POINTS);
    long p_inx = 0;

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
            else if (event.type == Event::MouseMoved 
                    && Mouse::isButtonPressed(Mouse::Left))
            {
                points[p_inx].position = Vector2f(event.mouseMove.x, event.mouseMove.y);
                p_inx < MAX_POINTS ? p_inx++ : p_inx = 0;
            }
            
            if (Keyboard::isKeyPressed(Keyboard::Enter))
            {
                convert_to_complex_plane(points, p_inx, complex_points);
                window.close();
            }

        window.clear();
        window.draw(points);
        draw_plane(window);
        window.display();
        }
    }
}

void draw_plane(RenderWindow &window)
{
    Vertex axis_x[] = {
        Vertex(Vector2f(0, (unsigned)(0.5 * WINDOW_HEIGHT))),
        Vertex(Vector2f(WINDOW_WIDTH, (unsigned)(0.5 * WINDOW_HEIGHT)))
    };

    Vertex axis_y[] = {
        Vertex(Vector2f((unsigned)(0.5 * WINDOW_WIDTH), 0)),
        Vertex(Vector2f((unsigned)(0.5 * WINDOW_WIDTH), WINDOW_HEIGHT))
    };

    window.draw(axis_x, 2, Lines);
    window.draw(axis_y, 2, Lines);
}

void convert_to_complex_plane(VertexArray &in, unsigned size, X_n &complex_set)
{
    int r, i; // real and imaginary part

    for (unsigned j = 0; j < size; ++j)
    {
        r = -(int)(WINDOW_WIDTH / 2) + in[j].position.x;
        i = (int)(WINDOW_HEIGHT / 2) - in[j].position.y;

        complex_set.push_back(r);
        complex_set.push_back(i);
    }
}
