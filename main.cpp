#include <iostream>
#include <limits>

enum Operation
{
    ADD,
    SUBTRACT,
    MULTIPLY,
    DIVIDE
};

void clearInputStream()
{
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int getInt()
{
    int num{};
    while (true)
    {
        std::cout << "Enter an integer: ";
        std::cin >> num;
        if (!std::cin)
        {
            clearInputStream();
            std::cout << "Invalid input. Please enter an integer.\n";
        }
        else
        {
            clearInputStream();
            return num;
        }
    }
}

Operation getOperation()
{
    char op{};
    while (true)
    {
        std::cout << "Get operation (*, + , -, /): ";
        std::cin >> op;
        if (!std::cin)
        {
            clearInputStream();
            std::cout << "Invalid input. Please enter a valid operation.\n";
        }
        else if (op == '+' || op == '-' || op == '*' || op == '/')
        {
            clearInputStream();
            switch (op)
            {
            case '+':
                return ADD;
            case '-':
                return SUBTRACT;
            case '*':
                return MULTIPLY;
            case '/':
                return DIVIDE;
            }
        }
        else
        {
            clearInputStream();
            std::cout << "Invalid input. Please enter a valid operation.\n";
        }
    }
}
int main()
{
    const int num1{getInt()};
    const int num2{getInt()};
    const Operation op{getOperation()};
    return 0;
}