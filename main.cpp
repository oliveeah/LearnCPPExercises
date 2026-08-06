#include <iostream>
#include <cstring>

auto foo(const char *str) -> void
{
    const char *start{str};
    const char *end{str + std::strlen(str) - 1};
    for (const char *p{start}; p <= end; ++p)
    {
        std::cout << *p;
    }
    std::cout << std::endl;
}

int main()
{
    foo("Hello, World!");
    return 0;
}