#include <iostream>
#include <vector>
#include <utility>

template <typename T>
auto findMinMaxValues (const std::vector<T>& vec) -> std::pair<T, T> {
    if(vec.empty()) {
        throw std::invalid_argument("Vector is empty");
    }

    const auto size { vec.size() };
    auto smallestValue { vec[0] }, largestValue { vec[0] };

    for (auto i {1uz}; i < size; ++i) {
        if (vec[i] < smallestValue) {
            smallestValue = vec[i];
        }
        if (vec[i] > largestValue) {
            largestValue = vec[i];
        }
    }
    return {smallestValue, largestValue};
}

template <typename T>
auto findMinMaxIndices (const std::vector<T>& vec) -> std::pair<std::size_t, std::size_t> {
    if(vec.empty()) {
        throw std::invalid_argument("Vector is empty");
    }

    const auto size { vec.size() };
    auto smallestValue { vec[0] }, largestValue { vec[0] };
    auto smallestIndex { 0uz }, largestIndex { 0uz };

    for (auto i {1uz}; i < size; ++i) {
        if (vec[i] < smallestValue) {
            smallestValue = vec[i];
            smallestIndex = i;
        }
        if (vec[i] > largestValue) {
            largestValue = vec[i];
            largestIndex = i;
        }
    }
    return {smallestIndex, largestIndex};
}

template <typename T>
auto printMinMaxValuesAndIndices (const std::vector<T>& vec) -> void {
    const auto [minIndex, maxIndex] = findMinMaxIndices(vec);
    const auto [minValue, maxValue] = findMinMaxValues(vec);

    std::cout << "With array (";
    for(const auto& value : vec) {
        std::cout << ' ' << value;
    }
    std::cout << " )\n";
    std::cout << "The min element has index " << minIndex << " and value " << minValue << '\n';
    std::cout << "The max element has index " << maxIndex << " and value " << maxValue << '\n';
}


int main() {
    printMinMaxValuesAndIndices(std::vector{ 3, 8, 2, 5, 7, 8, 3 });
    printMinMaxValuesAndIndices(std::vector{ 5.5, 2.7, 3.3, 7.6, 1.2, 8.8, 6.6 });
    return 0;
}