#include <SFML/Graphics.hpp>
#include <iostream>

#include "include/Canvi.hpp"
#include "include/Fourier.hpp"

int main()
{
    X_n x;
    main_drawer(x);
    for (auto &a : x)
    {
        std::cout << a << std::endl;
    }
}
