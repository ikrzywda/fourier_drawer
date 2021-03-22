#include <SFML/Graphics.hpp>
#include <iostream>

#include "include/Canvi.hpp"
#include "include/Fourier.hpp"
#include "include/Complex.hpp"

int main()
{
    C_set c, *coeffs;
    canvi_input(c);
    coeffs = DFT(c);

    for(auto &a : *coeffs)
    {
        std::cout << a.re << "," << a.im << "i" << std::endl;
    }
   
    canvi_output(coeffs);
}
