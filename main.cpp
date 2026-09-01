#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int guessVal(int num);
class Solution
{
public:
    int guessNumber(int n)
    {
        int MED{n / 2};
        int UB{n}, LB{1};
        while (true)
        {
            switch (int x = guessVal(MED))
            {
            case 1: // med is too small
                LB = MED + 1;
                UB = MED;
                break;
            case -1: // med is too big
                UB = MED - 1;
                break;
            case 0:
                return MED;
                break;
            }
            MED = LB + (UB - LB) / 2;
        }
        return 0;
    }
};
int main()
{
    vector<int> flowerbed{1, 0, 0, 0, 1};
    cout << canPlaceFlowers(flowerbed, 1) << "\n";
}