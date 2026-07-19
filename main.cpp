#include <iostream>
#include <vector>


int main()
{
    std::vector<int> vec = {1, 2, 3, 4, 5};
    std::cout << "vec size: " << std::size(vec) << '\n';
    std::cout << "vec at 1: " << vec.at(1) << '\n';

    return 0;
}