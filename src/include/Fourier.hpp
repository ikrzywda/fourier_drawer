#ifndef FOURIER_HPP
#define FOURIER_HPP

#include "Complex.hpp"

#include <cmath>
#include <vector>

typedef Complex<double> C;
typedef std::vector<C> C_set;

C_set *DFT(C_set input);    // Discrete Fourier Transform

C IDFT(C_set x_k, int n);   // Inverse Discrete Fourier Transform 

#endif
