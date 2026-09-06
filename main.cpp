#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int leftSum {},rightSum {};

        for (int num : nums) {
            rightSum += num;
        }
        
        for (auto i {0uz}; i < nums.size(); ++i) {
            rightSum -= nums[i];
            if(leftSum==rightSum)
                return static_cast<int>(i);            
            leftSum += nums[i];

        }
    return -1;
    }
};

int main()
{
  Solution sol;
  vector<int> nums = {1};
  int pivot = sol.pivotIndex(nums);
  cout << "Pivot index: " << pivot << endl;
}