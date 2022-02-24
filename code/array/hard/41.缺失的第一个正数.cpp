/*
 * @lc app=leetcode.cn id=41 lang=cpp
 *
 * [41] 缺失的第一个正数
 *
 * https://leetcode-cn.com/problems/first-missing-positive/description/
 *
 * algorithms
 * Hard (41.58%)
 * Likes:    1356
 * Dislikes: 0
 * Total Accepted:    193K
 * Total Submissions: 458K
 * Testcase Example:  '[1,2,0]'
 *
 * 给你一个未排序的整数数组 nums ，请你找出其中没有出现的最小的正整数。
 * 请你实现时间复杂度为 O(n) 并且只使用常数级别额外空间的解决方案。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [1,2,0]
 * 输出：3
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [3,4,-1,1]
 * 输出：2
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：nums = [7,8,9,11,12]
 * 输出：1
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * -2^31 
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        // 在原始数组上交换元素，保证空间复杂度为O(1)
        int n=nums.size();

        for(int i=0;i<n;++i) {
            // 这里if无法解决问题，要让当前元素i归位，且对于相同元素跳过交换，否则死循环
            while(nums[i]>0&&nums[i]<n&&nums[i]!=i+1&&nums[i]!=nums[nums[i]-1]) {
                // 索引为0的位置应当存放数字1，映射需要偏移
                swap(nums[i],nums[nums[i]-1]);
            }
        }

        for(int i=0;i<n;++i) {
            if(nums[i]!=i+1) {
                return i+1;
            }
        }
        return n+1;
    }
};
// @lc code=end

