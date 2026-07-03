#include "common.h"

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int maxSum = 0, sum = 0, len = (int)nums.size();
        


        for (int i = 0; i < k; i++)
        {
            sum += nums[i];
        }
        maxSum = sum;
        for (int i = k; i < len; i++)
        {
            sum = sum - nums[i - k] + nums[i];
            maxSum = max(maxSum, sum);
        }
        
        return ((double)maxSum / k);
    }
}solution;

int main() {
    vector<int> nums = { 5 };
    cout << "findMaxAverage:" << solution.findMaxAverage(nums, 1);
}