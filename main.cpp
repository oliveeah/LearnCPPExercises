#include <iostream>
#include <vector>
#include <utility>

auto foo (const std::vector<int>& vec) -> std::pair<int, int> {
    if(vec.empty())
    {
        return {0, 0};
    }

    const auto size { vec.size() };
    int smallest { vec[0] }, largest { vec[0] };
    for (auto i {0uz}; i < size; ++i) {
        if (vec[i] < smallest) {
            smallest = vec[i];
        }
        if (vec[i] > largest) {
            largest = vec[i];
        }
    }
    return {smallest, largest};

}


int main() {
    std::cout << std::pair<int,int>(foo({1, 2, 3, 4, 5})).first << std::endl;
    std::cout << std::pair<int,int>(foo({1, 2, 3, 4, 5})).second << std::endl;
    return 0;
}