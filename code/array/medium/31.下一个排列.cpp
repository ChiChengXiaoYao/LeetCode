/*
 * @lc app=leetcode.cn id=31 lang=cpp
 *
 * [31] 下一个排列
 *
 * https://leetcode-cn.com/problems/next-permutation/description/
 *
 * algorithms
 * Medium (37.32%)
 * Likes:    1290
 * Dislikes: 0
 * Total Accepted:    201.6K
 * Total Submissions: 540.1K
 * Testcase Example:  '[1,2,3]'
 *
 * 实现获取 下一个排列 的函数，算法需要将给定数字序列重新排列成字典序中下一个更大的排列（即，组合出下一个更大的整数）。
 * 
 * 如果不存在下一个更大的排列，则将数字重新排列成最小的排列（即升序排列）。
 * 
 * 必须 原地 修改，只允许使用额外常数空间。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [1,2,3]
 * 输出：[1,3,2]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [3,2,1]
 * 输出：[1,2,3]
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：nums = [1,1,5]
 * 输出：[1,5,1]
 * 
 * 
 * 示例 4：
 * 
 * 
 * 输入：nums = [1]
 * 输出：[1]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= nums.length <= 100
 * 0 <= nums[i] <= 100
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // 库函数next_permutation()
        // 2 3 5 4 1 找到5的位置
        // 降序排列的序列已经无法再变大，找到第一个非降序的位置
        int k=nums.size()-1;
        while(k>0&&nums[k-1]>=nums[k]) --k;
        // 特殊情况，当前数最大，返回最小序列
        if(k==0) {
            reverse(nums.begin(),nums.end());
        }
        else{
            // k后找到第一个比k-1大的数，保证交换后后面仍然保证降序，方便后续操作
            int t=k;
            while(t<nums.size()&&nums[t]>nums[k-1]) ++t;
            swap(nums[t-1],nums[k-1]);
            // 此时k-1为最大的数，[k,size)为降序排列，逆转之后即为升序
            reverse(nums.begin()+k,nums.end());
        }
    }
};
// @lc code=end

