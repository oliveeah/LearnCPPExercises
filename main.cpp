#include <iostream>
#include <string>
#include <string_view>
#include <vector>

template <typename T>
auto isValueInArray(const std::vector<T>& arr, const T& value) -> bool
{
    for(const auto& element : arr)
    {
        if(element == value) {
            std::cout << "Found: " << element << '\n';
            return true;
        }
    }
    std::cout << "Name not found." << '\n';
    return false;
}

int main() {
    const std::vector<std::string_view> names {"Alex", "Betty", "Caroline", "Dave", "Emily", "Fred", "Greg", "Holly"};
    
    std::string user_input;
    std::cout << "Enter a name to search for: ";
    std::getline(std::cin, user_input);

    (isValueInArray<std::string_view>(names, user_input)) 
        ? std::cout << "The name is in the array." << '\n'
        : std::cout << "The name is not in the array." << '\n';


}