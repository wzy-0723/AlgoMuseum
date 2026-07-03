#include "common.h"

int guess(int num)
{
	static int goal = 10;
	if (num > goal)return -1;
	else if (num < goal) return 1;
	else return 0;
}


class Solution {
public:
    int guessNumber(int n) {
        int right = 2147483647, left = 0;
        
		while (left <= right) {
			int mid = left + (right - left) / 2;
			int res = guess(mid);
			if (res == 0) return mid;
			else if (res == -1) right = mid - 1;
			else left = mid + 1;
		}

    }
};
Solution solution;


int main() {
	cout << solution.guessNumber(100) << endl;
}

/*
* 改题目前置条件为n>pick，所以右边界一定是n，而不是int的最大值
*
*/