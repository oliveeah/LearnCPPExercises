#ifndef POTION_H
#define POTION_H

#include <string_view>

class Potion
{
public:
    enum Type
    {
        healing,
        mana,
        speed,
        invisibility,
        maxType
    };

private:
    Type type{};
    int cost{};

public:
    Potion(Type type = healing, int cost = 0)
        : type(type), cost(cost) {}

    auto getEffect() const -> Type { return type; }
    auto getCost() const -> int { return cost; }
};

#endif