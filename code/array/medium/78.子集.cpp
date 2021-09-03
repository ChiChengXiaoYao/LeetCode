/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 *
 * https://leetcode-cn.com/problems/subsets/description/
 *
 * algorithms
 * Medium (80.03%)
 * Likes:    1307
 * Dislikes: 0
 * Total Accepted:    300.3K
 * Total Submissions: 375K
 * Testcase Example:  '[1,2,3]'
 *
 * 给你一个整数数组 nums ，数组中的元素 互不相同 。返回该数组所有可能的子集（幂集）。
 * 
 * 解集 不能 包含重复的子集。你可以按 任意顺序 返回解集。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [1,2,3]
 * 输出：[[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [0]
 * 输出：[[],[0]]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * -10 
 * nums 中的所有元素 互不相同
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int num = 1<<nums.size();
        vector<vector<int>> ans;
        ans.reserve(num);
        // 2**n种结果，从0-2**n-1，每种结果的二进制恰好表示nums的对应位置是否需要输出
        for(int i=0;i<num;++i) {
            vector<int> path;
            for(int j=0;j<nums.size();++j) {
                // 第i种结果的第j位是否需要输出
                if(i>>j & 1) {
                    path.push_back(nums[j]);
                }
            }
            ans.push_back(path);
        }
        return ans;
    }
};
// @lc code=end

