#include <iostream>
#include <vector>
#include <cassert>
#include <cstdint>

namespace Animals {
    enum Pets : uint8_t {
        chicken,
        dog,
        cat,
        elephant,
        duck,
        snake,
        max_pets
    };

    const std::vector numberOfLegs = {2, 4, 4, 4, 2, 0};
}

int main() {
    assert(Animals::numberOfLegs.size() == Animals::max_pets && "Number of legs array size does not match the number of pets.");
    std::cout << "Elephant has: " << Animals::numberOfLegs[Animals::elephant] << " legs." << '\n';
}