/*题目：
* 
* 递增的三元子序列
* 
* /


/*描述：
* 
* 给你一个整数数组 nums ，判断这个数组中是否存在长度为 3 的递增子序列。
* 
* 如果存在这样的三元组下标 (i, j, k) 且满足 i < j < k ，使得 nums[i] < nums[j] < nums[k] ，返回 true ；否则，返回 false 。
*
*/


/*示例：
* 
* 示例 1：
* 
* 输入：nums = [1,2,3,4,5]
* 输出：true
* 解释：任何 i < j < k 的三元组都满足题意
* 示例 2：
* 
* 输入：nums = [5,4,3,2,1]
* 输出：false
* 解释：不存在满足题意的三元组
* 示例 3：
* 
* 输入：nums = [2,1,5,0,4,6]
* 输出：true
* 解释：其中一个满足题意的三元组是 (3, 4, 5)，因为 nums[3] == 0 < nums[4] == 4 < nums[5] == 6
* 
*/


/*提示：
* 
* 
* 1 <= nums.length <= 5 * 105
* -231 <= nums[i] <= 231 - 1
* 
*/


/*解题思路：
* 
* 枚举一些情况可以得出
* 如果数组 nums 中存在一个下标 i 满足 1≤i<n−1，
* 使得在 nums[i] 的左边存在一个元素小于 nums[i] 且在 nums[i] 的右边存在一个元素大于 nums[i]，
* 则数组 nums 中存在递增的三元子序列。
* 
* 实现时和238类似，都是在索引位置建立信息节点。
* 创建两个长度为 n 的数组 leftMin 和 rightMax，对于 0≤i<n，
* leftMin[i] 表示 nums[0] 到 nums[i] 中的最小值，
* rightMax[i] 表示 nums[i] 到 nums[n−1] 中的最大值。
* 
* 数组 leftMin 的计算方式如下：
* leftMin[0]=nums[0]；
* 从左到右遍历数组 nums，对于 1≤i<n，leftMin[i]=min(leftMin[i−1],nums[i])。
* 
* 数组 rightMax 的计算方式如下：
* rightMax[n−1]=nums[n−1]；
* 从右到左遍历数组 nums，对于 0≤i<n−1，rightMax[i]=max(rightMax[i+1],nums[i])。
* 得到数组 leftMin 和 rightMax 之后，遍历 1≤i<n−1 的每个下标 i，
* 如果存在一个下标 i 满足 leftMin[i−1]<nums[i]<rightMax[i+1]，则返回 true，
* 如果不存在这样的下标 i，则返回 false。
*/


/*图示：
* 
* val
* 
*/