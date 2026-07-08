#include <iostream>
#include <string>
#include <string_view>

class Ball
{    
    private:
    static constexpr std::string_view m_default_color {"black"};
    static constexpr double m_default_radius {10.0};

    std::string m_color;
    double m_radius;

    public:
    Ball(double radius)
    : Ball{ m_default_color, radius }
    {}

    Ball(std::string_view color = m_default_color, double radius= m_default_radius)
    : m_color{color}
    , m_radius{radius}
    {}

    auto getColor() const -> const std::string& {return m_color;}
    auto getRadius() const -> double {return m_radius;}

};

auto printBall(const Ball& ball) -> void
{
    std::cout << "Ball(" << ball.getColor() << ", " << ball.getRadius() << ")\n";
}

int main(){

    Ball def{};
    Ball blue{ "blue" };
    Ball twenty{ 20.0 };
    Ball blueTwenty{ "blue", 20.0 };
    printBall(def);
    printBall(blue);
    printBall(twenty);
    printBall(blueTwenty);
    return 0;
}