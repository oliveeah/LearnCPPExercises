#include <iostream>
#include <vector>


int main()
{
    std::vector<int> results (3);

    std::cin >> results[0] >> results[1] >> results[2];

    std::cout << results[0] << results[1] << results[2];
    std::cout << results[0]+results[1]+results[2];
    std::cout << results[0]*results[1]*results[2];

    return 0;
}