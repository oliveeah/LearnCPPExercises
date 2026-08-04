#include <iostream>
#include <vector>
#include <utility>
#include <optional>
#include <limits>

template <typename T>
auto findMinMaxIndices(const std::vector<T> &vec) -> std::pair<std::size_t, std::size_t>
{
    if (vec.empty())
    {
        throw std::invalid_argument("Vector is empty");
    }

    const auto size{vec.size()};
    auto smallestIndex{0uz}, largestIndex{0uz};

    for (auto i{1uz}; i < vec.size(); ++i)
    {
        if (vec[i] < vec[smallestIndex])
        {
            smallestIndex = i;
        }
        if (vec[i] > vec[largestIndex])
        {
            largestIndex = i;
        }
    }
    return {smallestIndex, largestIndex};
}

template <typename T>
auto printMinMaxInfo(const std::vector<T> &vec) -> void
{
    const auto [minIndex, maxIndex] = findMinMaxIndices(vec);

    std::cout << "With array (";
    for (const auto &value : vec)
    {
        std::cout << ' ' << value;
    }
    std::cout << " )\n";
    std::cout << "The min element has index " << minIndex << " and value " << vec[minIndex] << '\n';
    std::cout << "The max element has index " << maxIndex << " and value " << vec[maxIndex] << '\n';
}

template <typename T = int>
auto createVector() -> std::optional<std::vector<T>>
{
    std::vector<T> vec{};
    T input{};
    bool sentinelEntered{false};

    std::cout << "Enter numbers to add (use -1 to stop): ";

    while (sentinelEntered == false)
    {
        std::cin >> input;
        if (input == T{-1})
        {
            sentinelEntered = true;
            break;
        }

        if (!std::cin)
        {
            std::cout << "Invalid input. Please enter a number.\n";
            std::cin.clear();                                                   // Clear the error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
            continue;
        }

        vec.push_back(input);

        for (const auto &value : vec)
        {
            std::cout << value << ' ';
        }
    }
    if (vec.empty())
    {
        return std::nullopt;
    }
    return vec;
}

int main()
{
    if (const auto vec = createVector())
    {
        printMinMaxInfo(*vec);
    }
    return 0;
}