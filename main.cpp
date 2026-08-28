#include <iostream>

class Fraction
{
private:
    int numerator{};
    int denominator{};

public:
    Fraction(int num, int denom)
        : numerator(num), denominator(denom)
    {
    }

    void print() const
    {
        std::cout << numerator << "/" << denominator << std::endl;
    }

    friend Fraction operator*(const Fraction &lhs, const Fraction &rhs)
    {
        return Fraction(lhs.numerator * rhs.numerator,
                        lhs.denominator * rhs.denominator);
    }

    friend Fraction operator*(const Fraction &lhs, int rhs)
    {
        return Fraction(lhs.numerator * rhs, lhs.denominator);
    }

    friend Fraction operator*(int lhs, const Fraction &rhs)
    {
        return Fraction(lhs * rhs.numerator, rhs.denominator);
    }
};

int main()
{
    Fraction f1{2, 5};
    f1.print();

    Fraction f2{3, 8};
    f2.print();

    Fraction f3{f1 * f2};
    f3.print();

    Fraction f4{f1 * 2};
    f4.print();

    Fraction f5{2 * f2};
    f5.print();

    Fraction f6{Fraction{1, 2} * Fraction{2, 3} * Fraction{3, 4}};
    f6.print();

    return 0;
}