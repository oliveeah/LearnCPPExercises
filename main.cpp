#include <string>
using namespace std;
#include <iostream>

class Solution
{
public:
    auto getValueFromSymbol(char currChar) -> int
    {
        int returnValue{};
        switch (currChar)
        {
        case 'I':
            returnValue = 1;
            break;
        case 'V':
            returnValue = 5;
            break;
        case 'X':
            returnValue = 10;
            break;
        case 'L':
            returnValue = 50;
            break;
        case 'C':
            returnValue = 100;
            break;
        case 'D':
            returnValue = 500;
            break;
        case 'M':
            returnValue = 1000;
            break;
        }
        return returnValue;
    }
    int romanToInt(string s)
    {
        int total{};
        int previousValue{};
        for (char c : s)
        {
            int currentValue{getValueFromSymbol(c)};
            total += currentValue;
            if (currentValue > previousValue)
            {
                total -= 2 * previousValue;
            }
            previousValue = currentValue;
        }
        return total;
    }
};

int main()
{
    Solution solution;
    std::string roman = "MCMXCIV";
    int result = solution.romanToInt(roman);
    std::cout << "Roman numeral: " << roman << ", Integer value: " << result << std::endl;
}