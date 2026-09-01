#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

bool canPlaceFlowers(vector<int> &flowerbed, int n)
{
    auto size{flowerbed.size()};
    auto streak{0};
    auto flowersPlanted{0};
    for (auto i{0uz}; i < size; ++i)
    {
        bool empty{flowerbed[i] == 0};
        bool leftEmpty{i == 0 || flowerbed[i - 1] == 0};
        bool rightEmpty{i == size - 1 || flowerbed[i + 1] == 0};

        if (empty && leftEmpty && rightEmpty)
        {
            flowerbed[i] = 1;
            ++flowersPlanted;
        }
    }
    return flowersPlanted >= n;
}

int main()
{
    vector<int> flowerbed{1, 0, 0, 0, 1};
    cout << canPlaceFlowers(flowerbed, 1) << "\n";
}