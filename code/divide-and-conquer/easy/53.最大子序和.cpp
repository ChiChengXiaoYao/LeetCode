/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子序和
 *
 * https://leetcode-cn.com/problems/maximum-subarray/description/
 *
 * algorithms
 * Easy (54.61%)
 * Likes:    3413
 * Dislikes: 0
 * Total Accepted:    566.6K
 * Total Submissions: 1M
 * Testcase Example:  '[-2,1,-3,4,-1,2,1,-5,4]'
 *
 * 给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [-2,1,-3,4,-1,2,1,-5,4]
 * 输出：6
 * 解释：连续子数组 [4,-1,2,1] 的和最大，为 6 。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [1]
 * 输出：1
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：nums = [0]
 * 输出：0
 * 
 * 
 * 示例 4：
 * 
 * 
 * 输入：nums = [-1]
 * 输出：-1
 * 
 * 
 * 示例 5：
 * 
 * 
 * 输入：nums = [-100000]
 * 输出：-100000
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * -10^5 
 * 
 * 
 * 
 * 
 * 进阶：如果你已经实现复杂度为 O(n) 的解法，尝试使用更为精妙的 分治法 求解。
 * 
 */

// @lc code=start
class Solution {
public:
    // 分治：每个区间分别求最大子段和、最大前缀、最大后缀、区间总和(最大前缀可能跨区间，需要该信息)
    // 时间复杂度O(n) 空间复杂度O(lgn)
    struct Node {
        int sum,s,ls,rs;
    };
    
    Node build(vector<int>& nums, int l, int r) {
        // 叶子节点
        if(l==r) {
            // 为负数时会被下面的max过滤掉
            return {nums[l],nums[l],nums[l],nums[l]};
        }

        int mid = l+r>>1;
        auto nl = build(nums, l, mid), nr = build(nums, mid+1, r);
        Node res;
        res.sum = nl.sum+nr.sum;    //区间总和
        res.ls = max(nl.ls, nl.sum+nr.ls);  //最大后缀
        res.rs = max(nr.rs, nr.sum+nl.rs);  //最大前缀
        res.s = max({nl.s,nr.s,nl.rs+nr.ls});   //最大子段和
        return res;
    }

    int maxSubArray(vector<int>& nums) {
        auto res = build (nums,0,nums.size()-1);
        return res.s;
    }
};
// @lc code=end

