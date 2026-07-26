#include <iostream>
#include <vector>
#include <cassert>

namespace Items
{
    enum Type
    {
        Health_Potion,
        Torch,
        Arrow,
        Max_Items
    };

}

auto countNumberOfItems(const std::vector<int>& inventory) -> int
{
    return std::ssize(inventory);
}

int main() {

    std::vector inventory { 1, 5, 10 };

    assert(countNumberOfItems(inventory) == Items::Max_Items && "Inventory size does not match the number of item types.");
    std::cout << "inventory size: " << countNumberOfItems(inventory) << std::endl;
    return 0;
}