#include <iostream>
#include <string_view>
#include <array>
#include <limits>
#include <string>
#include <cstdint>
#include <optional>

namespace Animal
{
    enum Type : uint8_t
    {
        chicken,
        dog,
        cat,
        elephant,
        duck,
        snake,
        max_animals
    };

    struct Data
    {
        int numberOfLegs{};
        std::string_view name{};
        std::string_view sound{};
    };

    constexpr std::array<Data, static_cast<std::size_t>(Type::max_animals)> animalData{
        {{2, "chicken", "cluck"},
         {4, "dog", "woof"},
         {4, "cat", "meow"},
         {4, "elephant", "trumpet"},
         {2, "duck", "quack"},
         {0, "snake", "hiss"}}};

    constexpr auto getAnimalData(Type type) -> const Data &
    {
        return animalData[static_cast<std::size_t>(type)];
    }

    constexpr auto printAnimalData(const Data &data) -> void
    {
        std::cout << "A " << data.name << " has " << data.numberOfLegs << " legs and says " << data.sound << ".\n";
    }

    constexpr auto isAnimal(std::string_view name) -> std::optional<Type>
    {
        const auto size{animalData.size()};
        for (auto i{0uz}; i < size; ++i)
        {
            if (animalData[i].name == name)
            {
                return static_cast<Type>(i);
            }
        }
        return std::nullopt;
    }
}

auto getAnimalFromUser() -> Animal::Type
{
    std::cout << "Enter an animal: ";

    while (true)
    {
        std::string input{};
        std::cin >> input;

        if (!std::cin)
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cerr << "Invalid input. Please enter an animal: ";
            continue;
        }

        if (!Animal::isAnimal(input))
        {
            std::cerr << "Invalid animal type. Please enter a valid animal: ";
            continue;
        }

        return *Animal::isAnimal(input);
    }
}

int main()
{
    Animal::printAnimalData(Animal::getAnimalData(getAnimalFromUser()));
    return 0;
}
