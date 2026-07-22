#include <iostream>
#include <vector>
#include <string_view>
#include <cassert>

auto FizzBuzz(int count) -> void
{
    const std::vector<int> divisors{ 3, 5, 7, 11, 13, 17, 19 };
    const std::vector<std::string_view> words{ "fizz", "buzz", "pop", "bang", "jazz", "pow", "boom" };

    assert(divisors.size() == words.size());
    const auto size = divisors.size();

    for (int i { 1 }; i < count; ++i) //foreach i->count
    {
        bool printed { false };
        for (auto j {0uz}; j < size; ++j)
        {
            if (i % divisors[j] == 0)
            {
                std::cout << words[j];
                printed = true;
            }
        }
        if (!printed)
        {
            std::cout << i;
        }
        std::cout << '\n';
    }

}



int main() {
    FizzBuzz(150);
    return 0;
}