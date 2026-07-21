#include <iostream>
#include <vector>

template <typename T>
auto printArray(const std::vector<T>& arr) -> void
{
    static const auto size { arr.size() };
    for (auto i {0uz}; i < size; ++i)
    {
        std::cout << arr[i] << " ";
    }
}

int main()
{
    std::vector arr{ 4, 6, 7, 3, 8, 2, 1, 9 };

    printArray(arr); // use function template to print array

    return 0;
}