
#include <vector>
using namespace std;
#include <iostream>
#include <numeric>
class Solution
{
public:
    string gcdOfStrings(string str1, string str2)
    {
        auto gcdSize{gcd(str1.size(), str2.size())};
        string candidate{str1.substr(0, gcdSize)};

        auto checkCandidate = [gcdSize, candidate](const string &str, size_t repeatCount)
        {
            for (auto i{0uz}; i < repeatCount; ++i)
            {
                if (str.substr(i * gcdSize, gcdSize) != candidate)
                    return false;
            }
            return true;
        };

        if (!checkCandidate(str1, str1.size() / gcdSize))
            return "";

        if (!checkCandidate(str2, str2.size() / gcdSize))
            return "";

        return candidate;
    }
};
int main()
{
    Solution solution;
    string str1{"ABAB"}, str2{"ABABAB"};
    cout << solution.gcdOfStrings(str1, str2) << endl;
    return 0;
}