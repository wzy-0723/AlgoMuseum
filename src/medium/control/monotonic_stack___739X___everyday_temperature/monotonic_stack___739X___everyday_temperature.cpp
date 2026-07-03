#include "common.h"

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        stack<int> stack_tempindex;
        vector<int> res(n, 0);
        for (int i = 0; i < temperatures.size(); i++)
        {
            while (!stack_tempindex.empty() && temperatures[i] > temperatures[stack_tempindex.top()])
            {
                int stackTopIndex = stack_tempindex.top();
                res[stackTopIndex] = i - stackTopIndex;
                stack_tempindex.pop();
            }
            stack_tempindex.push(i);
        }
		return res;
    }
}solution;

int main() {
    vector<int> temp = { 73,74,75,71,69,72,76,73 };
    vector<int> res = solution.dailyTemperatures(temp);
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << endl;
    }
}

/*
* 
* 
* 
* tempvec = {73,74,75,71,69,72,76,73}
* res     = { 1, 1, 4, 2, 1, 1, 0, 0}
* 
题目：
给定一个整数数组 temperatures ，表示每天的温度，返回一个数组 answer ，其中 answer[i] 是指对于第 i 天，下一个更高温度出现在几天后。
如果气温在这之后都不会升高，请在该位置用 0 来代替。

tips：
对于计算过程中被弹出的索引，他们本身已经得到了答案；
而且当前索引值必定比“被他弹出”的值大，因此，后续的值必定会在遍历到弹出索引值之前被“挡下来”，计算过程是无问题的。


示例 1:
输入: temperatures = [73,74,75,71,69,72,76,73]
输出: [1,1,4,2,1,1,0,0]

示例 2:
输入: temperatures = [30,40,50,60]
输出: [1,1,1,0]

示例 3:
输入: temperatures = [30,60,90]
输出: [1,1,0]
* 
*/