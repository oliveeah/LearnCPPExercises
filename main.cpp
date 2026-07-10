#include <iostream>

class Fraction
{
    private:
    static constexpr int kDefaultNumerator {0};
    static constexpr int kDefaultDenominator {1};

    int m_numerator {};
    int m_denominator {};

    public:
    explicit Fraction(int num = kDefaultNumerator, int denom = kDefaultDenominator)
     : m_numerator {num}
     , m_denominator {denom}
     {}

    auto getFraction() -> void
    {
        std::cout << "Enter a value for numerator: ";
        std::cin >> m_numerator; 
        std::cout << "Enter a value for denominator: ";
        std::cin >> m_denominator;
        std::cout << '\n';
    }

    auto multiply(const Fraction& multiplier) const -> Fraction
    {
        return Fraction {
            m_numerator * multiplier.m_numerator,
            m_denominator * multiplier.m_denominator
        };
    }

    auto print() const -> void
    {
        std::cout << m_numerator << '/' << m_denominator << '\n';
    }
};

auto main() -> int 
{
    Fraction f1 {};
    f1.getFraction();

    Fraction f2 {};
    f2.getFraction();

    f1.multiply(f2).print();
    return 0;
}