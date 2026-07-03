#include "common.h"
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.empty()) {
            return 0;
        }

        sort(intervals.begin(), intervals.end(), [](const auto& u, const auto& v) {
            return u[0] < v[0];
            });

        int n = intervals.size();
        vector<int> f(n, 1);
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (intervals[j][1] <= intervals[i][0]) {
                    f[i] = max(f[i], f[j] + 1);
                }
            }
        }
        return n - *max_element(f.begin(), f.end());
    }
}solution;


/*
注意到方法一本质上是一个「最长上升子序列」问题，因此我们可以将时间复杂度优化至 O(nlogn)，具体可以参考「300. 最长递增子序列的官方题解」。

算法思路：枚举（动态规划）
题目的要求等价于「选出最多数量的区间，使得它们互不重叠」。
由于选出的区间互不重叠，因此我们可以将它们按照端点从小到大的顺序进行排序，并且无论我们按照左端点还是右端点进行排序，得到的结果都是唯一的。

这样一来，我们可以先将所有的 n 个区间按照左端点（或者右端点）从小到大进行排序，随后使用动态规划的方法求出区间数量的最大值。
设排完序后这 n 个区间的左右端点分别为 L0，...，Ln−1 以及 R0，...，Rn−1，​
那么我们令 fi表示「以区间 i 为最后一个区间，可以选出的区间数量的最大值」.
状态转移方程即为：fi = max(j < i ∧ Rj <= Li){fj} + 1, 其中 j < i 且 rj ≤ li

即我们枚举倒数第二个区间的编号 j，满足 j<i，并且第 j 个区间必须要与第 i 个区间不重叠。
由于我们已经按照左端点进行升序排序了，因此只要第 j 个区间的右端点 Rj没有越过第 i 个区间的左端点 Li，
即 Rj <= Li，那么第 j 个区间就与第 i 个区间不重叠。
我们在所有满足要求的 j 中，选择 fj最大的那一个进行状态转移，
如果找不到满足要求的区间，那么状态转移方程中 max 这一项就为 0，fi就为 1。
最终的答案即为所有 fi中的最大值。
*/


int main() {
    cout << "hah哈哈";
}

/*
* 题目：
给定一个区间的集合 intervals ，其中 intervals[i] = [starti, endi] 。返回 需要移除区间的最小数量，使剩余区间互不重叠 。
注意：
只在一点上接触的区间是 不重叠的。例如 [1, 2] 和 [2, 3] 是不重叠的。

示例 1:
输入: intervals = [[1,2],[2,3],[3,4],[1,3]]
输出: 1
解释: 移除 [1,3] 后，剩下的区间没有重叠。

示例 2:
输入: intervals = [ [1,2], [1,2], [1,2] ]
输出: 2
解释: 你需要移除两个 [1,2] 来使剩下的区间没有重叠。

示例 3:
输入: intervals = [ [1,2], [2,3] ]
输出: 0
解释: 你不需要移除任何区间，因为它们已经是无重叠的了。
*
*/