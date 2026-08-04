#include <array>
#include <iostream>

auto printComma(std::size_t length, std::size_t index) -> void
{
    (index == length - 1) ? std::cout << "" : std::cout << ", ";
}
template <typename T, std::size_t N>
auto printArray(const std::array<T, N> &arr) -> void
{
    static_assert(N > 0, "Array must not be empty");

    std::cout << "The array (";

    for (auto i{0uz}; i < arr.size(); ++i)
    {
        std::cout << arr[i];
        printComma(arr.size(), i);
    }
    std::cout << ") has " << "length " << arr.size() << '\n';
}

int main()
{
    constexpr std::array arr1{1, 4, 9, 16};
    printArray(arr1);

    constexpr std::array arr2{'h', 'e', 'l', 'l', 'o'};
    printArray(arr2);

    return 0;
}