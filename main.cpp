#include <iostream>
#include <vector>
#include <cassert>
#include <string_view>

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

template <typename T>
auto getSize(const std::vector<T>& inventory) -> std::size_t
{
    return inventory.size();
}

template <typename T>
auto getNumberOfItems(const std::vector<T>& inventory) -> std::size_t
{
    const auto inventorySize = inventory.size();
    T totalItems {};
    for (auto i {0uz}; i < inventorySize; ++i)
    {
        totalItems += inventory[i];
    }
    return totalItems;
}

auto getItemName(Items::Type itemType) -> std::string_view
{
    switch (itemType)
    {
        case Items::Health_Potion:
            return "Health Potion";
        case Items::Torch:
            return "Torch";
        case Items::Arrow:
            return "Arrow";
        default:
            return "Unknown Item";
    }
}

template <typename T>
auto printNumberOfItems(const std::vector<T>& inventory) -> void
{
    const auto inventorySize = inventory.size();
    for (auto i {0uz}; i < inventorySize; ++i)
    {
        std::cout << "You have " << inventory[i] << " " << getItemName(static_cast<Items::Type>(i)) << '\n';
    }
}

template <typename T>
auto printTotalOfItems(const std::vector<T>& inventory) -> void
{
    std::cout << "You have " << getNumberOfItems(inventory) << " total items\n";
}


int main() {

    std::vector inventory { 1, 5, 10 };

    assert(getSize(inventory) == Items::Max_Items &&
        "Inventory size does not match the number of item types.");

    printNumberOfItems(inventory);

    printTotalOfItems(inventory);
    return 0;
}