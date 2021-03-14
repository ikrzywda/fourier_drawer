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
        X_k = C(0,0);
    }

    return out;
}

C_set *IDFT(C_set x_k)
{
    C_set *fs = new C_set;
    C temp, x_n;
    unsigned N = x_k.size();
    double a = (2 * M_PI) / N, x;

    for (unsigned n = 0; n < N; ++n)
    {
        for (unsigned k = 0; k < N; ++k)
        {
            x = a * n * k;     
            temp.re = cos(x);
            temp.im = sin(x);

            x_n += (temp * x_k[k]) / N;
        }

        fs->push_back(x_n);
        x_n = C(0,0);
    }

    return fs;
}
