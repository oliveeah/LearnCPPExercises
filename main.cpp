#include <iostream>
#include <vector>
#include <optional>
#include <limits>

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
auto searchArray(const std::vector<T>& arr, T number) -> std::optional<std::size_t>
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

template <typename T>
auto askUserForNumber(const char* prompt, T lower, T upper) -> T
{
    T number{};

    do
    {
        std::cout << prompt;
        std::cin >> number;

        if(!std::cin)
        {
            std::cin.clear();
        }

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    } while(number < lower || number > upper);

    return number;
}

int main()
{
    std::vector arr{ 4.4, 6.6, 7.7, 3.3, 8.8, 2.2, 1.1, 9.9 };
    const auto number { askUserForNumber("Please enter a number between 1 and 9 ", 1.0, 9.0) };

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