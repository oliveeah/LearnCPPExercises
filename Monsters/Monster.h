#ifndef MONSTER_H
#define MONSTER_H

#include <string>
#include <string_view>
#include <iostream>

class Monster
{
    //datamemembers
    public:
    enum MonsterType : int
    {
        Dragon,
        Goblin,
        Ogre,
        Orc,
        Skeleton,
        Troll,
        Vampire,
        Zombie,
        MaxMonsterTypes
    };  

    private:
    MonsterType m_type{};
    std::string m_name{};
    std::string m_roar{};
    int m_hitPoints{};

    //funcmembers
    public:
    Monster(MonsterType type, std::string_view name, std::string_view roar, int hitPoints)
    : m_type{type}
    , m_name{name}
    , m_roar{roar}
    , m_hitPoints{hitPoints}
    {}

    std::string_view getTypeString() const
    {
        switch(m_type)
        {
            case MonsterType::Dragon: return "Dragon";
            case MonsterType::Goblin: return "Goblin";
            case MonsterType::Ogre: return "Ogre";
            case MonsterType::Orc: return "Orc";
            case MonsterType::Skeleton: return "Skeleton";
            case MonsterType::Troll: return "Troll";
            case MonsterType::Vampire: return "Vampire";
            case MonsterType::Zombie: return "Zombie";
            default: return "Unknown";
        }
    }

    friend std::ostream& operator<<(std::ostream& out, const Monster& m)
    {
        return out << m.m_name << " the " << m.getTypeString() << " has " << m.m_hitPoints << " hit points and says " << m.m_roar << '\n';
    }
};

namespace MonsterGenerator
{
    Monster generateMonster()
    {
        return Monster{Monster::Dragon, "Default Name", "*ROAR*", 10};
    }
}

#endif // MONSTER_H