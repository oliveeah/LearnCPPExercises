#include <iostream>
#include <limits>
#include <cmath>

namespace
{
    constexpr int perfectSquares[]{0, 1, 4, 9};
    constexpr int sentinel{-1};
    constexpr int minPerfectSquare{perfectSquares[0]};
    constexpr int maxPerfectSquare{perfectSquares[std::size(perfectSquares) - 1]};
}

auto isPerfectSquare(int num) -> bool
{
    for (int square : perfectSquares)
    {
        if (num == square)
        {
            return true;
        }
    }
    return false;
}

auto getNumberFromUser() -> int
{
    std::cout << "Enter a single digit integer, or -1 to quit: ";
    int number{};
    while (true)
    {
        std::cin >> number;

        if (!std::cin)
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Enter a single digit integer, or -1 to quit: ";
            continue;
        }
        else if (number == sentinel || (number >= minPerfectSquare && number <= maxPerfectSquare))
        {
            return number;
        }
        std::cout << "Invalid input. Enter a single digit integer, or -1 to quit: ";
    }
}

int main()
{
    while (true)
    {
        int number{getNumberFromUser()};
        if (number == sentinel)
        {
            std::cout << "Exiting the program." << std::endl;
            break;
        }

        if (isPerfectSquare(number))
        {
            std::cout << number << " is a perfect square." << std::endl;
        }
        else
        {
            std::cout << number << " is not a perfect square." << std::endl;
        }
    }
    return 0;
}