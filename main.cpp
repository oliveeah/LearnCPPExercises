#include <iostream>
#include "Fraction.h"

auto getFraction() -> Fraction
{
    int x {};
    int y {};
    std::cout << "Enter a value for numerator: ";
    std::cin >> x; 
    std::cout << "Enter a value for denominator: ";
    std::cin >> y;
    std::cout << '\n';
    return Fraction{x,y};
}

auto print(const Fraction& f) -> void
{
    std::cout << f.getNumerator() << '/' << f.getDenominator() << '\n';
}

auto main() -> int 
{
    auto f1 {getFraction()};
    auto f2 {getFraction()};

    print(f1 * f2);

    return 0;
}