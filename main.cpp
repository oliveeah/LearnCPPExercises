#include <iostream>
#include <cmath>

class Point2d
{
private:
    double m_x {};
    double m_y {};

public:
    Point2d(double x = 0.0, double y = 0.0)
    : m_x {x}
    , m_y {y}
    {}

    auto print() const -> void
    {
        std::cout << "(" << m_x << ", " << m_y << ")\n";
    }

    auto distanceTo(const Point2d& p2) const -> double
    {
        return std::sqrt((m_x - p2.m_x)*(m_x - p2.m_x) + (m_y - p2.m_y)*(m_y - p2.m_y));
    }
};

auto main() -> int 
{
    Point2d first{};
    Point2d second{ 3.0, 4.0 };

    first.print();
    second.print();

    std::cout << "Distance between two points: " << first.distanceTo(second) << '\n';

    return 0;
}