/*
 * @lc app=leetcode.cn id=215 lang=cpp
 *
 * [215] 数组中的第K个最大元素
 *
 * https://leetcode-cn.com/problems/kth-largest-element-in-an-array/description/
 *
 * algorithms
 * Medium (64.69%)
 * Likes:    1485
 * Dislikes: 0
 * Total Accepted:    523.6K
 * Total Submissions: 809.2K
 * Testcase Example:  '[3,2,1,5,6,4]\n2'
 *
 * 给定整数数组 nums 和整数 k，请返回数组中第 k 个最大的元素。
 * 
 * 请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 
 * 输入: [3,2,1,5,6,4] 和 k = 2
 * 输出: 5
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: [3,2,3,1,2,4,5,5,6] 和 k = 4
 * 输出: 4
 * 
 * 
 * 
 * 提示： 
 * 
 * 
 * 1 
 * -10^4 
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    // 快速选择算法
    int findKthLargest(vector<int>& nums, int k) {
        return quick_sort(nums, 0, nums.size()-1, k);
    }

    int quick_sort(vector<int>& nums, int l, int r, int k) {
        if(l==r) {
            return nums[l];
        }

        int i=l-1,j=r+1;
        int hub=nums[l+r>>1];
        while(i<j) {
            while(nums[++i]>hub);
            while(nums[--j]<hub);
            if(i<j) {
                std::swap(nums[i],nums[j]);
            }
        }

        // j才是分界点，i不是，i和j并不一定相同
        int il = j-l+1;
        if(k<=il) {
            return quick_sort(nums, l, j, k);
        }
        return quick_sort(nums, j+1, r, k-il);
    }
};
// @lc code=end

