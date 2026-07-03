#include<iostream>

struct Monster 
{
    enum MonsterType
    {
        ogre,
		dragon,
		orc,
		giant_spider,
		slime,
    };

    const MonsterType type {};
    const std::string name {};
    int health {};
};

constexpr std::string_view getMonsterType (Monster::MonsterType type)
{
	switch (type)
	{
	case Monster::ogre:          return "Ogre";
	case Monster::dragon:        return "Dragon";
	case Monster::orc:           return "Orc";
	case Monster::giant_spider:  return "Giant Spider";
	case Monster::slime:         return "Slime";
	}

	return "Unknown";
} 

constexpr void PrintMonsterInfo(const Monster& monster)
{
    const std::string_view sv {monster.name};

    std::cout << "Monster Name: " << sv <<
     " Monster HP: " << monster.health <<
     " Monster Type: " << getMonsterType(monster.type) << '\n';

}


int main(){

	Monster ogre{ Monster::ogre, "Torg", 145 };
	Monster slime{ Monster::slime, "Blurp", 23 };    

    PrintMonsterInfo(ogre);
	PrintMonsterInfo(slime);

    return 0;
}