#include "Random.h"

#include <iostream>
#include <vector>

class SquareGame
{
private:
    int start{};
    int count{};
    int multiplier{};
    std::vector<int> numbers{};

    enum class GameEndState
    {
        Win,
        Fail
    };

    auto Generate_StartingNumber() -> int
    {
        std::cout << "Enter a number to start at: ";
        int start{};
        std::cin >> start;
        return start;
    }
    auto Generate_NOfNumbers() -> int
    {
        std::cout << "How many numbers to generate?: ";
        int count{};
        std::cin >> count;
        return count;
    }
    auto Generate_Vector(int start, int count, int multiplier) -> std::vector<int>
    {
        std::vector<int> numbers(static_cast<std::size_t>(count));
        int next{start};
        auto size{static_cast<std::size_t>(count)};
        for (auto i{0uz}; i < size; ++i)
        {
            numbers[i] = (next * next) * multiplier;
            ++next;
        }

        return numbers;
    }

public:
    SquareGame() : start(Generate_StartingNumber()),
                   count(Generate_NOfNumbers()),
                   multiplier(Random::get(2, 4)),
                   numbers(Generate_Vector(start, count, multiplier)) {}

    auto EndGame(GameEndState state) -> void
    {
        if (state == GameEndState::Win)
        {
            std::cout << "You win!" << '\n';
        }
        else
        {
            std::cout << "You lose!" << '\n';
        }
    }

    auto FindClosestNumber(int guess) -> int
    {
        int closest{numbers[0]};
        for (const auto &number : numbers)
        {
            if (std::abs(number - guess) < std::abs(closest - guess))
            {
                closest = number;
            }
        }

        return closest;
    }

    auto Guess() -> bool
    {
        std::cout << "What is the next number? ";
        int guess{};
        std::cin >> guess;

        if (FindAndRemove(guess))
        {
            std::cout << "Correct! " << --count << " number(s) left" << '\n';
            return true;
        }
        else
        {
            std::cout << "Incorrect!" << '\n';
            std::cout << "The closest number was " << FindClosestNumber(guess) << '\n';
            return false;
        }
    }

    auto FindAndRemove(int value) -> bool
    {
        auto found{std::find(numbers.begin(), numbers.end(), value)};
        if (found == numbers.end())
        {
            return false;
        }
        else
        {
            numbers.erase(found);
            return true;
        }
    }

    auto StartGame() -> void
    {
        std::cout << "I generated "
                  << count << " square numbers. Do you know what each number is after multiplying it by "
                  << multiplier << "?" << '\n';

        bool correctGuess{true};

        while (true)
        {
            correctGuess = Guess();

            if (numbers.empty())
            {
                EndGame(GameEndState::Win);
                break;
            }

            if (!correctGuess)
            {
                EndGame(GameEndState::Fail);
                break;
            }
        }
    }
};
int main()
{
    SquareGame game{};
    game.StartGame();

    return 0;
}
