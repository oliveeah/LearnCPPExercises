#include <algorithm>
#include <array>
#include <iostream>
#include <string_view>

bool print()
{
    std::cout << "print called";
    return true;
}

int main()
{
    // Print a value and count how many times @print has been called.
    auto print_{
        [](auto value)
        {
            static int callCount{0};
            std::cout << callCount++ << ": " << value << '\n';
        }};

    print_("hello"); // 0: hello
    print_("world"); // 1: world

    bool (*fnPtr)(){print}; // Function pointer to the print function

    print_(1); // 0: 1
    print_(2); // 1: 2

    print_("ding dong"); // 2: ding dong
    fnPtr();             // Call the print function through the function pointer
    return 0;
}
