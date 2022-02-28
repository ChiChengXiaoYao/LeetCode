/*
 * @lc app=leetcode.cn id=128 lang=cpp
 *
 * [128] 最长连续序列
 *
 * https://leetcode-cn.com/problems/longest-consecutive-sequence/description/
 *
 * algorithms
 * Medium (53.98%)
 * Likes:    1126
 * Dislikes: 0
 * Total Accepted:    218.1K
 * Total Submissions: 398.3K
 * Testcase Example:  '[100,4,200,1,3,2]'
 *
 * 给定一个未排序的整数数组 nums ，找出数字连续的最长序列（不要求序列元素在原数组中连续）的长度。
 * 
 * 请你设计并实现时间复杂度为 O(n) 的算法解决此问题。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [100,4,200,1,3,2]
 * 输出：4
 * 解释：最长数字连续序列是 [1, 2, 3, 4]。它的长度为 4。
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [0,3,7,2,5,8,4,6,0,1]
 * 输出：9
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 0 
 * -10^9 
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // 用Hash存储元素，然后从每段最小元素开始遍历个数
        int ans = 0;
        unordered_set<int> hash;
        for(auto x:nums) {
            hash.insert(x);
        }

        for(auto x:nums) {
            int y=1;
            if(hash.count(x)&&!hash.count(x-1)) {
                hash.erase(x);
                while(hash.count(++x)) {
                    hash.erase(x);
                    ++y;
                }
            }
            ans = max(ans, y);
        }
        return ans;
    }
};
// @lc code=end

