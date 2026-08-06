#include <iostream>
#include <array>
#include <string_view>
#include <cstddef>

namespace Potion
{
    enum Type
    {
        healing,
        mana,
        speed,
        invisibility,
        max_potions
    };

    constexpr std::array<Type, max_potions> types = {
        healing,
        mana,
        speed,
        invisibility};

    constexpr std::array<std::string_view, max_potions> names = {
        "Healing Potion",
        "Mana Potion",
        "Speed Potion",
        "Invisibility Potion"};

    constexpr std::array<int, max_potions> costs = {
        20,
        30,
        12,
        50};
}
void shop()
{
    std::cout << "Welcome to the Potion Shop!\n";
    for (auto p : Potion::types)
    {
        std::cout << "Potion Type: " << Potion::names[p] << ", Cost: " << Potion::costs[p] << "\n";
    }
}

int main()
{
    shop();
    return 0;
}