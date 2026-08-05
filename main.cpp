#include <iostream>
#include <string_view>
#include <array>

struct Item
{
    std::string_view name{};
    int gold{};
};

template <std::size_t N>
auto printStock(const std::array<Item, N> &items) -> void
{
    for (const auto &item : items)
    {
        std::cout << item.name << ": " << item.gold << " gold\n";
    }
}

int main()
{
    constexpr std::array<Item, 4> items{
        {{"Sword", 5},
         {"Dagger", 3},
         {"Club", 2},
         {"Spear", 7}}};
    printStock(items);

    return 0;
}