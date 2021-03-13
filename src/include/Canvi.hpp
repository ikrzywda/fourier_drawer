#ifndef CANVI_HPP
#define CANVI_HPP

#include "Fourier.hpp"
#include "Complex.hpp"

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <cmath>

using namespace sf;

void canvi_input(C_set &complex_points);

void canvi_output(C_set *complex_points);

void draw_IDFT(C_set *coeffs, VertexArray &drawing);

void draw_plane(RenderWindow &window);

void convert_to_complex_plane(VertexArray &in, unsigned size, C_set &complex_set);

void convert_to_canvas_plane(C_set &in, VertexArray &out);

#endif
