/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 *
 * https://leetcode-cn.com/problems/3sum/description/
 *
 * algorithms
 * Medium (32.66%)
 * Likes:    3539
 * Dislikes: 0
 * Total Accepted:    571K
 * Total Submissions: 1.7M
 * Testcase Example:  '[-1,0,1,2,-1,-4]'
 *
 * 给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？请你找出所有和为 0
 * 且不重复的三元组。
 * 
 * 注意：答案中不可以包含重复的三元组。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [-1,0,1,2,-1,-4]
 * 输出：[[-1,-1,2],[-1,0,1]]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = []
 * 输出：[]
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：nums = [0]
 * 输出：[]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 0 
 * -10^5 
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    // 时间复杂度O(n^2)
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for(int i=0;i<nums.size();++i) {
            if(i && nums[i]==nums[i-1]) continue;   //去重
            for(int j=i+1,k=nums.size()-1;j<k;++j) {
                // 没有该条判断时，[0,0,0,0]会输出[[0,0,0],[0,0,0]]，而非[[0,0,0]]
                if(j>i+1 && nums[j]==nums[j-1]) continue;
                // 从小到大枚举j时，也在从大到小枚举k，第二层for与第三层while实际为并列关系，共用复杂度O(n)
                while(j<k-1 && nums[i]+nums[j]+nums[k]>0) --k;
                if(nums[i]+nums[j]+nums[k]==0) {
                    ans.push_back({nums[i],nums[j],nums[k]});
                }
            }
        }
        return ans;
    }
};
// @lc code=end

