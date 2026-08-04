#include <array>
#include <iostream>

template <typename T, std::size_t N>
auto printArray(const std::array<T, N> &arr) -> void
{
    std::cout << "The array (";
    const auto length{arr.size()};
    for (auto i{0uz}; i < length; ++i)
    {
        std::cout << arr[i];
        if (i < length - 1)
        {
            std::cout << ", ";
        }
    }
    std::cout << ") has " << "length " << length << '\n';
}

int main()
{
    constexpr std::array arr1{1, 4, 9, 16};
    printArray(arr1);

    constexpr std::array arr2{'h', 'e', 'l', 'l', 'o'};
    printArray(arr2);

    return 0;
}