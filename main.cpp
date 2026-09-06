#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> set1 {};
        unordered_set<int> set2 {};

        for(auto i {0uz}; i < nums1.size(); ++i)
        {
          set1.emplace(nums1[i]);
        }
        for(auto i {0uz}; i < nums2.size(); ++i)
        {
          set2.emplace(nums2[i]);
        }

        vector<int> diff1 {};
        vector<int> diff2 {};

        for(const auto& value : set1)
        {
          if(set2.find(value) == set2.end())
          {
            diff1.push_back(value);
          }
        }

        for(const auto& value : set2)
        {
          if(set1.find(value) == set1.end())
          {
            diff2.push_back(value);
          }
        }
        return {diff1, diff2};
    }     
};
int main()
{
  Solution sol;
  vector<int> nums1 {1, 2, 3};
  vector<int> nums2 {2, 4, 6};
  auto result = sol.findDifference(nums1, nums2);
  for(auto& vec : result)
  {
    for(auto& num : vec)
    {
      cout << num << " ";
    }
    cout << endl;
  }

}