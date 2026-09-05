
#include <vector>
using namespace std;
#include <iostream>
#include <numeric>

class Solution
{
public:
    double findMaxAverage(vector<int> &nums, int k)
    {
        auto lw{0uz};
        auto rw{lw + static_cast<size_t>(k)};
        int highestSum{};
        auto numsSize{nums.size()};

        for (auto i{0uz}; i < rw; ++i)
        {
            highestSum += nums[i];
        }

        int lastSum = highestSum;

        for (; rw < numsSize; ++rw)
        {
            int prevWindowSum = (lastSum - nums[lw]);
            int currentSum = (prevWindowSum + nums[rw]);

            if (currentSum > highestSum)
            {
                highestSum = currentSum;
            }

            ++lw;
            lastSum = currentSum;
        }

        return static_cast<double>(highestSum) / k;
    }
};

int main()
{
    Solution solution;
    vector<int> nums{5};
    cout << solution.findMaxAverage(nums, 1) << endl;
    return 0;
}