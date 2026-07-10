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

    auto getNumerator() const -> int {return m_numerator;}
    auto getDenominator() const -> int {return m_denominator;}

    auto multiply(const Fraction& multiplier) const -> Fraction
    {
        return Fraction {
            m_numerator * multiplier.m_numerator,
            m_denominator * multiplier.m_denominator
        };
    }
};

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
    Fraction f1 {getFraction()};
    Fraction f2 {getFraction()};

    print(f1.multiply(f2));

    return 0;
}