
#include <vector>
using namespace std;
#include <iostream>

class Solution
{
public:
    string mergeAlternately(string word1, string word2)
    {
        if (word1.empty())
            return word2;
        if (word2.empty())
            return word1;

        string result{};
        auto count{0uz}, word1Size{word1.size()}, word2Size{word2.size()};

        while (count < word1Size || count < word2Size)
        {
            if (count < word1Size)
            {
                result.push_back(word1[count]);
            }
            if (count < word2Size)
            {
                result.push_back(word2[count]);
            }
            ++count;
        }
        return result;
    }
};

int main()
{
    Solution solution;
    string word1{"ab"}, word2{"pqrs"};
    string result{solution.mergeAlternately(word1, word2)};
    cout << result << endl;
}