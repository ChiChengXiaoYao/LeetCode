/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 *
 * https://leetcode-cn.com/problems/permutations/description/
 *
 * algorithms
 * Medium (78.21%)
 * Likes:    1528
 * Dislikes: 0
 * Total Accepted:    401.4K
 * Total Submissions: 513K
 * Testcase Example:  '[1,2,3]'
 *
 * 给定一个不含重复数字的数组 nums ，返回其 所有可能的全排列 。你可以 按任意顺序 返回答案。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [1,2,3]
 * 输出：[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [0,1]
 * 输出：[[0,1],[1,0]]
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：nums = [1]
 * 输出：[[1]]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * -10 
 * nums 中的所有整数 互不相同
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> ans;
    vector<int> path;
    vector<bool> st;
    vector<vector<int>> permute(vector<int>& nums) {
        path.resize(nums.size());
        st.resize(nums.size());

        dfs(nums,0);
        return ans;
    }

    void dfs(vector<int>& nums, int u) {
        if(u==nums.size()) {
            ans.push_back(path);
            return;
        }

        for(int i=0;i<nums.size();++i) {
            if(st[i]==false) {
                path[u]=nums[i];
                st[i]=true;
                dfs(nums,u+1);
                st[i]=false;
            }
        }
    }
};
// @lc code=end

