#include "Random.h"

#include <iostream>
#include <vector>

int main()
{
    std::cout << "Enter a number to start at: ";
    int start{};
    std::cin >> start;

    std::cout << "How many numbers to generate?: ";
    int count{};
    std::cin >> count;

    const int multiplier{Random::get(2, 4)}; // generate a random number between 2 and 4
    std::cout << "Multiplier: " << multiplier << '\n';

    std::vector<int> numbers{};

    for (int i{}, next{start}; i < count; ++i)
    {
        numbers.push_back((next * next) * multiplier);
        ++next;
        std::cout << "Generated number: " << numbers.back() << '\n';
    }

    std::cout << "I generated " << numbers.size()
              << " numbers. Do you know what each number is after multiplying by "
              << multiplier << "?" << '\n';

    return 0;
}
