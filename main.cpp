
#include <vector>
using namespace std;
#include <iostream>
#include <numeric>

class Solution
{
public:
    bool isSubsequence(string s, string t)
    {
        auto s_p{0uz}, t_p{0uz};
        for (; t_p < t.size(); ++t_p)
        {
            if (t[t_p] == s[s_p])
            {
                ++s_p;
                if (s_p >= s.size())
                {
                    return true;
                }
            }
        }
        return false;
    }
};

int main()
{
    Solution solution;
    bool i = solution.isSubsequence(string{"axc"}, string{"ahbgdc"});
    std::cout << boolalpha << i << std::endl;
    return 0;
}