#include "common.h"

class Solution {
public:
    int countOnes(int x) {
        int ones = 0;
        while (x > 0) {
            x &= (x - 1);
            ones++;
        }
        return ones;
    }

    vector<int> countBits(int n) {
        vector<int> bits(n + 1);
        for (int i = 0; i <= n; i++) {
            bits[i] = countOnes(i);
        }
        return bits;
    }
};
Solution solution;


int main() {
    vector<int> res = solution.countBits(10);
    for (int i = 0; i < res.size(); i++)
    {
        cout << "countBits:" << res[i] << endl;
    }
    
}

/*
* 
* 题目：
* 给你一个整数 n ，对于 0 <= i <= n 中的每个 i ，计算其二进制表示中 1 的个数 ，返回一个长度为 n + 1 的数组 ans 作为答案。
* 例如：
* 输入：n = 5  输出：[0,1,1,2,1,2]
* 运算过程：
* 0 --> 0
* 1 --> 1
* 2 --> 10
* 3 --> 11
* 4 --> 100
* 5 --> 101
*
*/


/*
* 计算某个数的二进制中“1”的个数
* 最直观的做法是对从 0 到 n 的每个整数直接计算「一比特数」。每个 int 型的数都可以用 32 位二进制数表示，只要遍历其二进制表示的每一位即可得到 1 的数目。
*
* 利用 Brian Kernighan 算法：
* 可以在一定程度上进一步提升计算速度。
* 原理是：对于任意整数 x，令 x=x & (x−1)，该运算将 x 的二进制表示的最后一个 1 变成 0。
* 因此，对 x 重复该操作，直到 x 变成 0，则操作次数即为 x 的「一比特数」。
* 
* 一般规律：
* 设bits[x]为x二进制下“1”的个数
* 令y = x & (x - 1)，则有bits[x] = bits[y] + 1
* 可以用来作动态规划解法（一维），从下标1开始计算，公式为：bits[i] = bits[i & (i - 1)] + 1;
*/