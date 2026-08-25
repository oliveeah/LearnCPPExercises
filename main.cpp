#include <iostream>
#include <functional>
namespace
{
    using ArithmeticFunction = std::function<int(int, int)>;
}

int getInteger()
{
    std::cout << "Enter an integer: ";
    int x{};
    std::cin >> x;
    return x;
}

char getOperation()
{
    char op{};

    do
    {
        std::cout << "Enter an operation ('+', '-', '*', '/'): ";
        std::cin >> op;
    } while (op != '+' && op != '-' && op != '*' && op != '/');

    return op;
}

int add(int x, int y)
{
    return x + y;
}
int subtract(int x, int y)
{
    return x - y;
}
int multiply(int x, int y)
{
    return x * y;
}
int divide(int x, int y)
{
    return x / y;
}

ArithmeticFunction getArithmeticFunction(char op)
{
    switch (op)
    {
    case '+':
        return &add;
    case '-':
        return &subtract;
    case '*':
        return &multiply;
    case '/':
        return &divide;
    }
    return nullptr;
}

int main()
{
    int x{getInteger()};
    char op{getOperation()};
    int y{getInteger()};

    int result{getArithmeticFunction(op)(x, y)};
    if (result)
        std::cout << x << " " << op << " " << y << " = " << result << std::endl;

    return 0;
}