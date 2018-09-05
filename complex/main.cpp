#include <iostream>
#include "complex.h"

using namespace CSC_212_Summer_2018;

int main() {
    complex c1;
    std::cout << "Value of c1 is: " << c1 << std::endl;
    complex c2(1);
    std::cout << "Value of c2 is: " << c2 << std::endl;
    complex c3(2, 3);
    std::cout << "Value of c3 is: " << c3 << std::endl;
    complex c4 = c3;
    std::cout << "Value of c4 is: " << c4 << std::endl;
    complex c5(c3);
    std::cout << "Value of c5 is: " << c5 << std::endl;
    c5 = c2;
    std::cout << "Value of c5 is: " << c5 << std::endl;
    complex c6;
    std::cout << "Enter the imaginary and real part of the number: " << std::endl;
    std::cin >> c6;
    std::cout << "Value of c6 is: " << c6 << std::endl;
    complex c7 = c2 + c3;
    std::cout << "Value of c7 is: " << c7 << std::endl;
    return 0;
}