#include <iostream>
#include <vector>
#include <string_view>

int main() {

    std::vector evenNumbers { 2, 4, 6, 8, 10 };
    const std::vector otherNumberss { 1.2, 3.4, 5.6, 7.8 };
    const std::vector<std::string_view> names { "Alice", "Bob", "Charlie" };

    return 0;
}