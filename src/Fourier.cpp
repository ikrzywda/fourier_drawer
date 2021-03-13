#include "include/Fourier.hpp"

C_set *DFT(C_set input)
{
    C_set *out = new C_set;
    C temp, X_k;
    unsigned N = input.size();
    double a = (2 * M_PI) / N, x;

    for (unsigned k = 0; k < N; ++k)
    {
        for (unsigned n = 0; n < N; ++n)
        {
            x = a * n * k;
            temp.re = cos(x);
            temp.im = -sin(x);

            X_k += (temp * input[n]);
        }

        out->push_back(X_k);
    }

    return out;
}

C IDFT(C_set *x_k, int n)
{
    return C();
}
