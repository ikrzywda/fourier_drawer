#ifndef FOURIER_HPP
#define FOURIER_HPP

#include <cmath>
#include <vector>

typedef std::vector<int> X_n;

X_n *DFT(X_n input);    // Discrete Fourier Transform

X_n *IDFT(X_n input);   // Inverse Discrete Fourier Transform 

#endif
