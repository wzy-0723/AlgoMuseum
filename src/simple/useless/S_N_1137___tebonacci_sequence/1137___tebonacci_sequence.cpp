#include "common.h"

class Solution {
public:
    int tribonacci(int n) {
        vector<int> seq = { 0,1,1 };
        if (n < 3)return seq[n];


        for (int i = 3; i < n + 1; i++)
        {
            seq.push_back(seq[i - 1] + seq[i - 2] + seq[i - 3]);
        }
        return seq[n];
    }
};
Solution solution;


int main() {
    cout << "tribonacci:" << solution.tribonacci(4);
}

/*
* 泰波那契序列 Tn 定义如下： 
* T0 = 0, T1 = 1, T2 = 1, 且在 n >= 0 的条件下 Tn+3 = Tn + Tn+1 + Tn+2
* 给你整数 n，请返回第 n 个泰波那契数 Tn 的值。
*
*/