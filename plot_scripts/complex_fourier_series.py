#!/usr/bin/python

from matplotlib import pyplot as plt
import numpy as np
import math as m
import sys

def generate_fs(coeff, freq):
    
    fs = np.fromfunction(
            np.vectorize(lambda i : 
                complex(np.cos((i * freq) / 100), np.sin((i * freq) / 100)) * coeff),
            (629,), 
            dtype=complex)

    return fs

def plot_fs(coeff, epicycles, step):

    fs = list()

    for i in range(0, len(coeff)):
        fs.append(generate_fs(coeff[i], i+1))


    if epicycles: 
        for i in range(len(fs)):
            plt.plot(fs[i].real, fs[i].imag)
            plt.plot([0,fs[i].real[step]], [0,fs[i].imag[step]])
            plt.plot([0,fs[i].real[step]], [0,0], 'k--')
            plt.plot([fs[i].real[step],fs[i].real[step]], [0,fs[i].imag[step]], 'k--')
    else:
        out = np.add(fs[0],fs[1],fs[2])
        plt.plot(out.real, out.imag)

    plt.gca().set_aspect('equal', adjustable='box')
    plt.xlabel('real')
    plt.ylabel('imaginary')
    #plt.show()
    plt.savefig('dsf_explainer_1.png')
    

if __name__ == '__main__':
    coeffs = np.array([3+4j])
    plot_fs(coeffs, True, 5)
