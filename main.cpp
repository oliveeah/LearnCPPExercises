#include <iostream>

class Fraction
{
    private:
    int numerator {};
    int denominator {};

    public:
    Fraction() : Fraction{0, 1} {}

    Fraction(int num, int denom) : numerator{num}, denominator{denom} {}

    auto getNumerator() const -> int {return numerator;}
    auto getDenominator() const -> int {return denominator;}

    auto setNumerator(int newNumerator) -> void {numerator = newNumerator;}
    auto setDenominator(int newDenominator) -> void {denominator = newDenominator;}

    auto print() const -> void
    {
        std::cout << numerator << '/' << denominator << '\n';
    }

    auto multiply(const Fraction& multiplier) -> void
    {
        numerator *= multiplier.numerator;
        denominator *= multiplier.denominator;

        std::cout << "New fraction after multiplication: ";
        print();
    }
};

auto getFraction() -> Fraction
{
    Fraction temp{};
    int num {};
    int denom {};
    std::cout << "Enter a value for numerator: ";
    std::cin >> num;
    temp.setNumerator(num);
    std::cout << "Enter a value for denominator: ";
    std::cin >> denom;
    temp.setDenominator(denom);
    std::cout << '\n';
    return temp;
}

auto main() -> int 
{
    Fraction f1{ getFraction() };
    Fraction f2{ getFraction() };

    std::cout << "Your fractions multiplied together: ";

    f1.multiply(f2);
    
    return 0;
}