//
// Created by Nooreddin on 6/15/2018.
//

#ifndef CLASS_PROGRAM_COMPLEX_H
#define CLASS_PROGRAM_COMPLEX_H

#include <iostream>

namespace CSC_212_Summer_2018 {
    class complex {
        friend std::istream &operator>>(std::istream &, complex &);

    public:
        complex(double real = 0, double imag = 0);

        double real() const { return m_real; }

        double imag() const { return m_imag; }

    private:
        double m_real;
        double m_imag;
    };

    complex operator+(const complex &, const complex &);

    std::ostream &operator<<(std::ostream &, const complex &);
}
#endif //CLASS_PROGRAM_COMPLEX_H
