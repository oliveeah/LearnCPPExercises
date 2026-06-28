#include <iostream>
#include <string_view>
enum Direction { North, East, South, West };

constexpr Direction& CalcNewDirection(Direction& dir)
{
    switch (dir)
    {
        case North: dir = East; break;
        case East: dir = South; break;
        case South: dir = West; break;
        case West: dir = North; break;
    }
    return dir;
}

constexpr std::string_view DirectionToString(Direction dir)
{
    switch (dir)
    {
        case North: return "North";
        case East: return "East";
        case South: return "South";
        case West: return "West";
    }
    
}

std::ostream& operator<<(std::ostream& out, Direction dir)
{
    out << DirectionToString(dir);
    return out;  
}

Direction& operator++(Direction& dir)
{
    std::cout << "Current direction: " << dir << '\n';
    return CalcNewDirection(dir);
}

int main ()
{        
    Direction dir { North };

    for (int i {}; i < 4; ++i)
    {
        ++dir;
        std::cout << "New direction: " << dir << '\n';
    }

    return 0;
}