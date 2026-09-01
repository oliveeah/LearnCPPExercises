#include <string>
using namespace std;
#include <iostream>
#include <vector>

class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        if (strs.empty())
            return "";

        auto result{std::min_element(strs.begin(), strs.end(), [](string const &a, string const &b)
                                     { return a.size() < b.size(); })};

        string prefix = *result;
        size_t shortestString = prefix.size();

        size_t strCount = strs.size();
        for (size_t i = 0; i < shortestString; ++i)
        {
            for (size_t j = 0; j < strCount; ++j)
            {
                if (strs[j][i] != prefix[i])
                {
                    prefix.resize(i);
                    return prefix;
                }
            }
        }
        return prefix;
    }
};

int main()
{
    Solution solution;
    vector<string> strs = {"flower", "flow", "flight"};
    string result = solution.longestCommonPrefix(strs);
    std::cout << "Longest common prefix: " << result << std::endl;
}