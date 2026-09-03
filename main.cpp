
#include <vector>
using namespace std;
#include <iostream>

class Solution
{
public:
    int removeElement(vector<int> &nums, int val)
    {

        if (nums.empty())
            return 0;

        const auto size{nums.size()};
        auto write{0uz};
        auto read{0uz};
        for (; read < size; ++read)
        {
            if (nums[read] != val)
            {
                nums[write] = nums[read];
                ++write;
            }
        }

        return static_cast<int>(write);
    }
};

int main()
{
    Solution solution;
    vector<int> nums{3, 2, 2, 3};
    int val = 3;
    int newLength = solution.removeElement(nums, val);
    std::cout << "New length: " << newLength << std::endl;
    auto *array{new int[5]{5, 4, 3, 2, 1}}; // initializer list
    delete[] array;                         // free the allocated memory
}