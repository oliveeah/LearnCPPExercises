#ifndef TRIAD_H
#define TRIAD_H

#include <iostream>

template <typename T, typename U, typename V>
class Triad
{
private:
    T m_first {};
    U m_second {};
    V m_third {};

public:
    Triad(const T& first, const U& second, const V& third)
    : m_first{first}
    , m_second{second}
    , m_third{third}
    {}

    auto first() const -> const T& { return m_first; }
    auto second() const -> const U& { return m_second; }
    auto third() const -> const V& { return m_third; }

    auto print() const -> void;
};

template<typename T, typename U, typename V>
void Triad<T, U, V>::print() const
{
    std::cout << "[" << m_first << ", " << m_second << ", " << m_third << "]";
}

#endif // TRIAD_H