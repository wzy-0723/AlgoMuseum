#include "common.h"

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int left = 0, right = 0;

        int len = nums.size();

        while (right < len)
        {
            if (nums[right] != 0)
            {
                swap(nums[left], nums[right]);
                left++;
            }
            right++;
        }
    }
}solution;

int main() {
    vector<int> nums = { 4,2,4,0,0,3,0,5,1,0 };
    solution.moveZeroes(nums);

    for (auto num : nums)
    {
        cout << num << endl;
    }
    
}