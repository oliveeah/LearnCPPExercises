#include "PotionShop.h"
#include <algorithm>

std::ostream &operator<<(std::ostream &os, const Potion::Type &type)
{
    switch (type)
    {
    case Potion::healing:
        os << "Healing";
        break;
    case Potion::mana:
        os << "Mana";
        break;
    case Potion::speed:
        os << "Speed";
        break;
    case Potion::invisibility:
        os << "Invisibility";
        break;
    default:
        os << "Unknown";
        break;
    }
    return os;
}

std::istream &operator>>(std::istream &is, Potion::Type &type)
{
    std::string input;
    is >> input;

    if (input == "Healing")
        type = Potion::healing;
    else if (input == "Mana")
        type = Potion::mana;
    else if (input == "Speed")
        type = Potion::speed;
    else if (input == "Invisibility")
        type = Potion::invisibility;
    else if (input == "exit")
        is.setstate(std::ios::eofbit);
    else
        is.setstate(std::ios::failbit);

    return is;
}

void PotionShop::printStock() const
{
    std::cout << "Potion Shop Stock:\n";
    printSeparator();
    for (const auto &p : potions)
    {
        std::cout << p.getEffect() << " potion costs " << p.getCost() << " gold.\n";
    }
    std::cout << "exit - Exit the shop\n";
    printSeparator();
}

void PotionShop::buyPotion(int &wallet)
{
    Potion::Type choice{};
    printStock();

    while (true)
    {
        std::cout << "Enter the type of potion you want to buy: ";
        std::cin >> choice;
        switch (std::cin.rdstate())
        {
        case std::ios::eofbit:
            std::cout << "Exiting the shop.\n";
            return;
        case std::ios::failbit:
            std::cout << "Invalid potion type. Please try again.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        if (getSufficientFunds(wallet, choice))
        {
            updateStock(choice);
            printSeparator();
            std::cout << "You have purchased a " << choice << " potion.\n";
            std::cout << "Remaining wallet balance: " << wallet << " gold.\n";
            printSeparator();
            printStock();
        }
        else
        {
            std::cout << "Insufficient funds.\n";
        }
    }
}

void PotionShop::updateStock(Potion::Type type)
{
    std::erase_if(potions, [type](const Potion &p)
                  { return p.getEffect() == type; }); // MEDIUM: Use of std::erase_if to remove the purchased potion from stock
}

bool PotionShop::getSufficientFunds(int &wallet, Potion::Type type)
{
    for (const auto &p : potions)
    {
        if (p.getEffect() == type)
        {
            if (wallet >= p.getCost())
            {
                wallet -= p.getCost();
                return true;
            }
            return false;
        }
    }
    return false;
}