#include <iostream>
#include <string>

std::string EnterName(int person_number)
{
    std::cout << "Enter name for person " << person_number << ": ";
    std::string name {};
    std::getline(std::cin >> std::ws, name);
    return name;
}

int EnterAge(int person_number)
{
    std::cout << "Enter age for person " << person_number << ": ";
    int age {};
    std::cin >> age;
    return age;
}

void PrintPersonInfo(std::string_view name_1, int age_1, std::string_view name_2, int age_2)
{
    if (age_1 == age_2)
    {
        std::cout << name_1 << " and " << name_2 << " are the same age.\n";
    } 
    else if (age_1 > age_2)
    {
        std::cout << name_1 << " is older than " << name_2 << ".\n";
    }
    else
    {
        std::cout << name_2 << " is older than " << name_1 << ".\n";
    }
}


int main() {

    const std::string kNameOne {EnterName(1)};
    const std::string kNameTwo {EnterName(2)};
    const int kAgeOne {EnterAge(1)};
    const int kAgeTwo {EnterAge(2)};

    PrintPersonInfo(kNameOne, kAgeOne, kNameTwo, kAgeTwo);  

    return 0;
    
}