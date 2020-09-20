/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */
#include <vector>
#include <unordered_map>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // map用红黑树实现，适合有序的情况
        // unordered_map用Hash实现，适合查找
        unordered_map<int, int> indices;
        for (int i = 0; i < nums.size(); i++) {
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

