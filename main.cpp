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
auto findLargestNumber(const std::vector<T>& arr) -> T
{
    const auto size { arr.size() };

    if (size == 0)
    {
        return T {};
    }
    
    T largest { arr[0] };
    for (auto i {1uz}; i < size; ++i)
    {
        if (arr[i] > largest)
        {
            largest = arr[i];
        }
    }
    return largest;
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
    std::vector data1 { 84, 92, 76, 81, 56 };
    std::cout << findLargestNumber(data1) << '\n';

    std::vector data2 { -13.0, -26.7, -105.5, -14.8 };
    std::cout << findLargestNumber(data2) << '\n';

    std::vector<int> data3 { };
    std::cout << findLargestNumber(data3) << '\n';
    //printArray(arr); // use function template to print array

    return 0;
}