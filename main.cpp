#include <iostream>
#include <string_view>
#include <array>
#include <limits>
#include <string>
#include <cstdint>
#include <optional>

namespace Animal
{
    enum Type
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

    constexpr auto animalCount{static_cast<std::size_t>(Type::max_animals)};

    constexpr std::array<Data, animalCount> animalData{
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

    auto printAnimalData(const Data &data) -> void
    {
        std::cout << "A " << data.name << " has " << data.numberOfLegs << " legs and says " << data.sound << ".\n";
    }

    constexpr auto isAnimalName(std::string_view name) -> std::optional<Type>
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

    static_assert(animalData.size() == animalCount, "Animal data size does not match the number of animal types.");
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

        if (auto animal{Animal::isAnimalName(input)})
        {
            return *animal;
        }
        std::cerr << "Invalid animal type. Please enter a valid animal: ";
    }
}

int main()
{
    Animal::printAnimalData(Animal::getAnimalData(getAnimalFromUser()));
    return 0;
}
