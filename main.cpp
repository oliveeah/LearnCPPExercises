#include "Random.h"

#include <iostream>
#include <array>
#include <string>
#include <string_view>
#include <limits>
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

    constexpr std::array types = {
        healing,
        mana,
        speed,
        invisibility};

    constexpr std::array<std::string_view, max_potions> names = {
        "Healing Potion",
        "Mana Potion",
        "Speed Potion",
        "Invisibility Potion"};

    constexpr std::array costs = {
        20,
        30,
        12,
        50};
}

class Player
{
private:
    std::string_view m_name{};
    constexpr static int m_gold_LB{80};
    constexpr static int m_gold_UB{120};
    int m_gold{};
    [[maybe_unused]] std::array<int, Potion::max_potions> m_inventory{};

public:
    Player(std::string_view name = "Player") : m_name{name}
    {
        m_gold = Random::get(m_gold_LB, m_gold_UB);
    }

    auto getGold() const -> int { return m_gold; }
    auto addToInventory(Potion::Type type, int value) -> void
    {
        if (value < 0)
            return;
        m_inventory[type] += value;
    }
};

void shop()
{

    std::cout << "Welcome to the Potion Shop!\n";

    while (true)
    {
        std::cout << "What is your name: ";
        std::string name{};
        std::getline(std::cin >> std::ws, name);
        if (!std::cin)
        {
            std::cout << "Error reading input. Please try again.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        Player player{name};
        std::cout << "Hello, " << name << "! You have " << player.getGold() << " gold.\n";
        break;
    }

    for (auto p : Potion::types)
    {
        std::cout << "Potion Type: " << Potion::names[p] << ", Cost: " << Potion::costs[p] << "\n";
    }

    std::cout << "Thanks for shopping at Roscoe's potion emporium!\n";
}

int main()
{
    shop();
    return 0;
}