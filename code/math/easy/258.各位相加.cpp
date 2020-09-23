/*
 * @lc app=leetcode.cn id=258 lang=cpp
 *
 * [258] 各位相加
 *
 * https://leetcode-cn.com/problems/add-digits/description/
 *
 * algorithms
 * Easy (67.84%)
 * Likes:    282
 * Dislikes: 0
 * Total Accepted:    50.8K
 * Total Submissions: 74.9K
 * Testcase Example:  '38'
 *
 * 给定一个非负整数 num，反复将各个位上的数字相加，直到结果为一位数。
 * 
 * 示例:
 * 
 * 输入: 38
 * 输出: 2 
 * 解释: 各位相加的过程为：3 + 8 = 11, 1 + 1 = 2。 由于 2 是一位数，所以返回 2。
 * 
 * 
 * 进阶:
 * 你可以不使用循环或者递归，且在 O(1) 时间复杂度内解决这个问题吗？
 * 
 */

// @lc code=start
class Solution {
public:
    int addDigits(int num) {
        // 逢十进一，表示和的结果-9，多次进位则多次-9
        // 数字本身是9，则无法进位，需要排除
        // 数字是9的倍数，则最终还是会减到9
        if(num%9 == 0 && num)   return 9;
        return (num%9);
    }
};
// @lc code=end

