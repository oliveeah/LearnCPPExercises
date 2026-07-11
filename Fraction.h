#ifndef FRACTION_H
#define FRACTION_H

class Fraction
{
private:
    static constexpr int kDefaultNumerator {0};
    static constexpr int kDefaultDenominator {1};

    int m_numerator {};
    int m_denominator {};

public:
    explicit Fraction(int num = kDefaultNumerator, int denom = kDefaultDenominator);

    auto getNumerator() const -> int {return m_numerator;}
    auto getDenominator() const -> int {return m_denominator;}

    auto multiply(const Fraction& multiplier) const -> Fraction;

    auto operator*(const Fraction& multiplier) const -> Fraction;
};  

#endif // FRACTION_H