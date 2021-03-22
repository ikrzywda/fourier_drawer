#ifndef FOURIER_HPP
#define FOURIER_HPP

#include "Complex.hpp"

#include <cmath>
#include <vector>

typedef Complex<double> C;
typedef std::vector<C> C_set;

C_set *DFT(C_set input);    // Discrete Fourier Transform

C_set *IDFT(C_set x_k);   // Inverse Discrete Fourier Transform 

#endif
