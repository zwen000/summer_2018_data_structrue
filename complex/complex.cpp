//
// Created by Nooreddin on 6/15/2018.
//

#include "complex.h"

namespace CSC_212_Summer_2018 {

    complex::complex(double real, double imag) {
        m_real = real;
        m_imag = imag;
    }

    std::istream &operator>>(std::istream &ins, complex &second) {
        ins >> second.m_real >> second.m_imag;

        return ins;
    }

    complex operator+(const complex &c1, const complex &c2) {
        double sum_real = c1.real() + c2.real();
        double sum_imag = c1.imag() + c2.imag();
        complex sum(sum_real, sum_imag);

        return sum;
    }

    std::ostream &operator<<(std::ostream &outs, const complex &c) {
        outs << c.real();

        if (c.imag() >= 0) {
            outs << "+" << c.imag() << "i";
        } else {
            outs << c.imag() << "i";
        }
        return outs;
    }

}