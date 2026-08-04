#include <iostream>
#include <array>

int main()
{
    constexpr std::array<char, 5> arr = {'H', 'e', 'l', 'l', 'o'};
    std::cout << "Array length is: " << arr.size() << std::endl;
    std::cout << "last element is: " << arr[4] << std::endl;
    std::cout << "last element is: " << arr.at(4) << std::endl;
    std::cout << "last element is: " << std::get<4>(arr) << std::endl;

    return 0;
}