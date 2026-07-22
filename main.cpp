#include <iostream>
#include <vector>
#include <optional>

template <typename T>
auto printArray(const std::vector<T>& arr) -> void
{
    const auto size { arr.size() };
    for (auto i {0uz}; i < size; ++i)
    {
        std::cout << arr[i] << ' ';
    }
}

template <typename T>
auto searchArray(const std::vector<T>& arr, T& number) -> std::optional<std::size_t>
{
    const auto size { arr.size() };
    for (auto i {0uz}; i < size; ++i)
    {
        if (arr[i] == number)
        {
            return i;
        }
    }
    return std::nullopt;
}

auto askUserForNumber() -> int
{
    int number {};
    std::cout << "Enter a number between 1 and 9 inclusive: ";
    do {
        std::cin >> number;
        if(!std::cin)
        {
            std::cout << "Invalid input. Please enter a number between 1 and 9 inclusive.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
    }
    while(number < 1 || number > 9);
    
    return number;
}


int main()
{
    std::vector arr{ 4, 6, 7, 3, 8, 2, 1, 9 };
    int number { askUserForNumber() };

    auto result { searchArray(arr, number) };
    if(result)
    {
        std::cout << "The number " << number << " is found at index " << *result << ".\n";
    }
    else
    {
        std::cout << "The number " << number << " is not found in the array.\n";
    }
    //printArray(arr); // use function template to print array

    return 0;
}