#include <iostream>
#include <cstring>

auto foo(const char *str) -> void
{
    if (str == nullptr)
    {
        std::cerr << "Empty string\n";
        return;
    }

    const auto len{std::strlen(str)};

    if (len == 0)
    {
        std::cerr << "Empty string\n";
        return;
    }

    const char *end{str + len};

    for (const char *ptr{--end}; ptr >= str; --ptr)
    {
        std::cout << *ptr;
    }
    std::cout << '\n';
}

int main()
{
    foo("Hello, World!");
    return 0;
}