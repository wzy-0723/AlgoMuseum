#include "common.h"

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int left = -1;//表示左指针
        int ans = 0;//表示子数组中1的数量
        int left0 = 0, right0 = 0;//表示子数组中0的数量
        for (int right = 0; right < nums.size(); right++) {
            right0 += 1 - nums[right];//从右指针为0开始向后遍历，1-nums[r]就是计算0的数量，如果nums[r]为0，cnt0就会加一
            while (right0 - left0 > 1)
            {
                left0 += 1 - nums[++left];
            }

            ans = max(ans, right - left - 1);
        }
        return ans;
    }
}solution;

int main() {
    std::vector<int> vec = { 1,1,0,1 };
    solution.longestSubarray(vec);
}