
#include <vector>
using namespace std;
#include <iostream>

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        if (nums.empty())
            return 0;

        auto numsSize{nums.size()};
        auto read_p{1uz};
        auto write_p{1uz};
        auto lastNum{nums[0]};

        for (; read_p < numsSize; ++read_p)
            if (nums[read_p] != lastNum)
            {
                nums[write_p] = nums[read_p];
                lastNum = nums[read_p];
                ++write_p;
            }

        return write_p;
    }
};