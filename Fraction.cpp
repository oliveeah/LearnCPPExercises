#include "Fraction.h"
#include <stdexcept>

Fraction::Fraction(int num, int denom)
    : m_numerator {num}
    , m_denominator {denom}
{
    if (denom == 0)
    throw std::runtime_error("Denominator cannot be zero");
}

auto Fraction::multiply(const Fraction& multiplier) const -> Fraction
{
    return Fraction {
        m_numerator * multiplier.m_numerator,
        m_denominator * multiplier.m_denominator
    };
}