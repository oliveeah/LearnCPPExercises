#include <iostream>
#include <string>
#include <string_view>

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

    MonsterType type {};
    std::string name {};
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

std::ostream& operator<< (std::ostream& out, const Monster::MonsterType type)
{
    return out << getMonsterType(type);
}

void PrintMonsterInfo(const Monster& monster)
{
    std::cout << "Monster Name: " << monster.name <<
     " Monster HP: " << monster.health <<
     " Monster Type: " << monster.type << '\n';
}


int main(){

	Monster ogre{ Monster::ogre, "Torg", 145 };
	Monster slime{ Monster::slime, "Blurp", 23 };    

    PrintMonsterInfo(ogre);
	PrintMonsterInfo(slime);

    return 0;
}