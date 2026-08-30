#include <iostream>
#include <string>

int main()
{
    const char *bar = "bar";
    const char *bar = "bar";
    std::string a = "a";
    auto a1 = [a]()
    {
        std::string a = "aa";
        return a;
    };
    std::cout << a1();
}