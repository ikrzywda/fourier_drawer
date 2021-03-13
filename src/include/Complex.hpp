#ifndef COMPLEX_HPP
#define COMPLEX_HPP

template <class T>
struct Complex
{
    T re = 0, 
      im = 0;

    Complex(T re, T im)
    {
        this->re = re;
        this->im = im;
    }

    Complex(){}

    Complex operator=(Complex n)
    {
        this->re = n.re;
        this->im = n.im;

        return *this;
    };

    Complex operator+(Complex n)
    {
        this->re += n.re;
        this->im += n.im;

        return *this;
    };

    Complex operator-(Complex n)
    {
        this->re += n.re;
        this->im += n.im;

        return *this;
    };

    Complex operator+=(Complex n)
    {
        this->re += n.re;
        this->im += n.im;

        return *this;
    };

    Complex operator*(Complex n)
    {
        Complex t;

        t.re = this->re * n.re - this->im * n.im;
        t.im = this->re * n.im + this->im * n.re;

        *this = t;

        return *this;
    };

};

#endif
