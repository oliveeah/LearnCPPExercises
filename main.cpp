#include <iostream>
#include <vector>
#include <utility>


template <typename T>
auto findMinMaxIndices (const std::vector<T>& vec) -> std::pair<std::size_t, std::size_t> {
    if(vec.empty()) {
        throw std::invalid_argument("Vector is empty");
    }

    auto smallestIndex { 0uz }, largestIndex { 0uz };

    for (auto i {1uz}; i < vec.size(); ++i) {
        if (vec[i] < vec[smallestIndex]) {
            smallestIndex = i;
        }
        if (vec[i] > vec[largestIndex]) {
            largestIndex = i;
        }
    }
    return {smallestIndex, largestIndex};
}

template <typename T>
auto printMinMaxInfo (const std::vector<T>& vec) -> void {
    const auto [minIndex, maxIndex] = findMinMaxIndices(vec);

    std::cout << "With array (";
    for(const auto& value : vec) {
        std::cout << ' ' << value;
    }
    std::cout << " )\n";
    std::cout << "The min element has index " << minIndex << " and value " << vec[minIndex] << '\n';
    std::cout << "The max element has index " << maxIndex << " and value " << vec[maxIndex] << '\n';
}


int main() {
    printMinMaxInfo(std::vector{ 3, 8, 2, 5, 7, 8, 3 });
    printMinMaxInfo(std::vector{ 5.5, 2.7, 3.3, 7.6, 1.2, 8.8, 6.6 });
    return 0;
}