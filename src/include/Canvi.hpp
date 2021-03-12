#ifndef CANVI_HPP
#define CANVI_HPP

#include "Fourier.hpp"

#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;

void main_drawer(X_n &complex_points);

void draw_plane(RenderWindow &window);

void convert_to_complex_plane(VertexArray &in, unsigned size, X_n &complex_set);

#endif
