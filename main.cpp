#include <iostream>

class Ball
{
    public:
    Ball(std::string_view color, double radius)
    : m_color{color}
    , m_radius{radius}
    {}

    auto getColor() const -> const std::string& {return m_color;}
    auto getRadius() const -> double {return m_radius;}

    private:
    std::string m_color {};
    double m_radius {};
};

auto printBall(const Ball& ball) -> void
{
    std::cout << "Ball(" << ball.getColor() << ", " << ball.getRadius() << ")\n";
}

int main(){

    Ball ball1{"red", 5.0};
    printBall(ball1);
    return 0;
}