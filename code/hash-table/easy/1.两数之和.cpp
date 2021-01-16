/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 *
 * https://leetcode-cn.com/problems/two-sum/description/
 *
 * algorithms
 * Easy (49.41%)
 * Likes:    9199
 * Dislikes: 0
 * Total Accepted:    1.4M
 * Total Submissions: 2.8M
 * Testcase Example:  '[2,7,11,15]\n9'
 *
 * 给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。
 * 
 * 你可以假设每种输入只会对应一个答案。但是，数组中同一个元素不能使用两遍。
 * 
 * 
 * 
 * 示例:
 * 
 * 给定 nums = [2, 7, 11, 15], target = 9
 * 
 * 因为 nums[0] + nums[1] = 2 + 7 = 9
 * 所以返回 [0, 1]
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    // 抽象：扫描到某个数时，是否有另一个数与当前数之和为所给值
    // 查找/插入一个数，Hash时间复杂度为O(1)，平衡树时间复杂度为O(log(n))
    vector<int> twoSum(vector<int>& nums, int target) {
        // map用红黑树实现，适合有序的情况
        // unordered_map用Hash实现，适合查找
        unordered_map<int, int> indices;
        for (int i = 0; i < nums.size(); i++) {
            // find的替代：count，可以返回对应有多少项(又因为map的Key唯一，所以返回0/1)
            if (indices.find(target - nums[i]) != indices.end()) {
                // 这玩意就是个用列表初始化构造了一个vector，放在return死活没认出来
                return {indices[target - nums[i]], i};
            }
            // 先查找再添加本次值，避免重复查值(6=3+3)的情况
            // 根据值查索引，所以Key=数组值，Value=数组索引
            indices[nums[i]] = i;
        }
        return {};
    }
};
// @lc code=end

