#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

bool isPalindrome(int x)
{
    if (x < 0)
        return false;

    int digits{}, temp{x};
    int division{1};

    while (temp > 1)
    {
        temp /= 10;
        division *= 10;
        digits++;
    }
    digits++;

    int numcomparisons = digits / 2;
    int modulo{10};

    while (true)
        if ((x % modulo) / (modulo / 10) != (x / division) % 10)
        {
            return false;
        }
        else
        {
        }
    modulo *= 10;
    division /= 10;
}

return true;
}

int main()
{
    cout << isPalindrome(1234321) << "\n";
}