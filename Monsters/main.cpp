#include "Monster.h"

#include <iostream>

int main()
{
    Monster m2 {MonsterGenerator::generateMonster()};
    std::cout << m2;
    return 0;
}