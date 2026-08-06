#ifndef POTIONSHOP_H
#define POTIONSHOP_H

#include "Potion.h"

#include <iostream>
#include <string_view>
#include <vector>

class PotionShop
{
private:
    std::vector<Potion> potions{
        Potion(Potion::healing, 20),
        Potion(Potion::mana, 30),
        Potion(Potion::speed, 10),
        Potion(Potion::invisibility, 50)};

    auto updateStock(Potion::Type type) -> void;
    auto getSufficientFunds(int &wallet, Potion::Type type) -> bool;

public:
    auto printStock() const -> void;
    auto buyPotion(int &wallet) -> void;
};

auto operator<<(std::ostream &os, const Potion::Type &type) -> std::ostream &;
auto operator>>(std::istream &is, Potion::Type &type) -> std::istream &;
auto printSeparator() -> void { std::cout << "------------------------------------\n"; }
#endif