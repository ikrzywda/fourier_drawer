#!/usr/bin/python

from matplotlib import pyplot as plt
import numpy as np
import math as m
import sys


def wrap_function(func_in, freq):

    N = len(func_in)
    data = np.zeros(N, dtype = np.complex_)
    theta = (6.28 / N) * freq
    coeff = complex(0,0)

    for n in range(0, N):
        c = complex(m.cos(theta * n), -(m.sin(theta * n)))
        data[n] = func_in[n] * c
        coeff += data[n]

    coeff /= N

    return (data, coeff)


def plot_complex(data, name):

    plt.plot(data[0].real, data[0].imag)
    plt.scatter(data[1].real, data[1].imag)
    plt.axhline(y=0, color='k')
    plt.axvline(x=0, color='k')
    plt.savefig(sys.argv[1])

    plt.show()


if __name__ == '__main__':
    dt = np.zeros(628)
    x = np.arange(0,6.28,0.01)
    for i in range(0,628):
        dt[i] = m.cos(10 * i/100) + m.cos(20 * i/100) + m.sin(25 * i/100)
    
    #plt.plot(x, dt)
    #plt.show()
    #plt.savefig(sys.argv[1])
    plot_complex(wrap_function(dt, 25), sys.argv[1])
