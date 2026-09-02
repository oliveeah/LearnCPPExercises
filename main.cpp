#include <string>
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        if (s.empty())
            return 0;

        int longestStreak{};
        unordered_set<char> charSet{};

        auto wL{0uz};
        auto size{s.size()};

        for (auto wR{0uz}; wR < size; ++wR)
        {
            while (charSet.contains(s[wR]))
            {
                charSet.erase(s[wL]);
                ++wL;
            }

            charSet.insert(s[wR]);

            const auto currentStreak{wR - wL + 1};

            if (currentStreak > longestStreak)
                longestStreak = currentStreak;
        }

        return longestStreak;
    }
};