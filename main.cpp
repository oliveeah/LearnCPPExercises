#include <iostream>
#include <string>
#include <string_view>
#include <vector>

int main() {
    const std::vector<std::string_view> names {"Alex", "Betty", "Caroline", "Dave", "Emily", "Fred", "Greg", "Holly"};
    
    std::string user_input;
    std::cout << "Enter a name to search for: ";
    std::getline(std::cin, user_input);

    for(const auto& name : names)
    {
        if(name == user_input) {
            std::cout << "Found: " << name << '\n';
            return 0;
        }
    }
    std::cout << "Name not found." << '\n';
    return 0;
}