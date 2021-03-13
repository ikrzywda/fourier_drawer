#include "include/Canvi.hpp"

using namespace sf;

const unsigned MAX_POINTS = 30000;
const int HALF_WINDOW_WIDTH = 400;
const int HALF_WINDOW_HEIGHT = 400;

void canvi_input(C_set &complex_points)
{
    RenderWindow window(VideoMode(2 * HALF_WINDOW_WIDTH, 2 * HALF_WINDOW_HEIGHT), 
                        "Fourier Sketchpad",
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
                points[p_inx].position = Vector2f(event.mouseMove.x, 
                                                  event.mouseMove.y);

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

void canvi_output(C_set *input)
{
    unsigned n = 0;
    std::string prompt = "n = ";
    VertexArray drawing(Points, MAX_POINTS);

    RenderWindow window(VideoMode(2 * HALF_WINDOW_WIDTH, 2 * HALF_WINDOW_HEIGHT), 
                        "Fourier Drawer",
                        Style::Close);

    Font font;
    if (!font.loadFromFile("assets/fonts/ostrich-regular.ttf"))
        std::cout << "Could not load font from file" << std::endl;

    Text text;
    text.setFont(font);
    text.setCharacterSize(24);
    text.setFillColor(Color::White);

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
            }
            
            if (Keyboard::isKeyPressed(Keyboard::Enter))
            {
                window.close();
            }
            else if (Keyboard::isKeyPressed(Keyboard::K)) 
            {
                if(event.type == Event::KeyReleased)
                    ++n;
            }
            else if (Keyboard::isKeyPressed(Keyboard::J))
            {
                if(event.type == Event::KeyReleased)
                    n > 0 ? --n : n;
            }
                
    text.setString(prompt + std::to_string(n));
    draw_IDFT(input, drawing);

    window.clear();
    draw_plane(window);
    window.draw(text);
    window.draw(drawing);
    window.display();
    }
}

void draw_IDFT(C_set *coeffs, VertexArray &drawing)
{
    unsigned i = 0;
    int x = 0, y = 0;

    for (double theta = 0; theta < (2 * M_PI); theta += 0.01)
    {
        for (unsigned n = 0; n < coeffs->size(); ++n)
        {
            x += coeffs->at(n).re + cos(n * theta);  
            y += coeffs->at(n).im + sin(n * theta);  
            drawing[i] = Vector2f(x + 400, y + 400);
            ++i;
        }
    }

}

void draw_plane(RenderWindow &window)
{
    Vertex axis_x[] = {
        Vertex(Vector2f(0, HALF_WINDOW_HEIGHT)),
        Vertex(Vector2f(2 * HALF_WINDOW_WIDTH, HALF_WINDOW_HEIGHT))
    };

    Vertex axis_y[] = {
        Vertex(Vector2f(HALF_WINDOW_WIDTH, 0)),
        Vertex(Vector2f(HALF_WINDOW_WIDTH, 2 * HALF_WINDOW_HEIGHT))
    };

    window.draw(axis_x, 2, Lines);
    window.draw(axis_y, 2, Lines);
}

void convert_to_complex_plane(VertexArray &in, unsigned size, C_set &complex_set)
{
    double r, i; // real and imaginary part

    for (unsigned j = 0; j < size; ++j)
    {
        r = -HALF_WINDOW_WIDTH + in[j].position.x;
        i = HALF_WINDOW_HEIGHT - in[j].position.y;

        complex_set.push_back(C(r,i));
    }
}

void convert_to_canvas_plane(C_set &in, VertexArray &out)
{
}
