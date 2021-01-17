/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个正序数组的中位数
 *
 * https://leetcode-cn.com/problems/median-of-two-sorted-arrays/description/
 *
 * algorithms
 * Hard (39.24%)
 * Likes:    3603
 * Dislikes: 0
 * Total Accepted:    318.9K
 * Total Submissions: 808.6K
 * Testcase Example:  '[1,3]\n[2]'
 *
 * 给定两个大小为 m 和 n 的正序（从小到大）数组 nums1 和 nums2。请你找出并返回这两个正序数组的中位数。
 * 
 * 进阶：你能设计一个时间复杂度为 O(log (m+n)) 的算法解决此问题吗？
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：nums1 = [1,3], nums2 = [2]
 * 输出：2.00000
 * 解释：合并数组 = [1,2,3] ，中位数 2
 * 
 * 
 * 示例 2：
 * 
 * 输入：nums1 = [1,2], nums2 = [3,4]
 * 输出：2.50000
 * 解释：合并数组 = [1,2,3,4] ，中位数 (2 + 3) / 2 = 2.5
 * 
 * 
 * 示例 3：
 * 
 * 输入：nums1 = [0,0], nums2 = [0,0]
 * 输出：0.00000
 * 
 * 
 * 示例 4：
 * 
 * 输入：nums1 = [], nums2 = [1]
 * 输出：1.00000
 * 
 * 
 * 示例 5：
 * 
 * 输入：nums1 = [2], nums2 = []
 * 输出：2.00000
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * nums1.length == m
 * nums2.length == n
 * 0 <= m <= 1000
 * 0 <= n <= 1000
 * 1 <= m + n <= 2000
 * -10^6 <= nums1[i], nums2[i] <= 10^6
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    //如果对时间复杂度的要求有log，通常都需要用到二分查找
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int total = nums1.size() + nums2.size();
        if(total%2) {
            return find(nums1,0,nums2,0,total/2+1);
        } else {
            int left = find(nums1,0,nums2,0,total/2);
            int right = find(nums1,0,nums2,0,total/2+1);
            return (left+right)/2.0;
        }
    }

    // 在两个有序数组中，找到第k小的数
    // 数组1，寻找起点1，数组2，寻找起点2，第k小的数字
    int find(vector<int>& nums1, int i, vector<int>& nums2, int j, int k) {
        // nums1比nums2长的处理，统一后可以简化代码
        if(nums1.size()-i>nums2.size()-j) return find(nums2,j,nums1,i,k);
        // num1已经找完了，则仅仅查找num2的第k个元素(num2[j]为起点)
        if(nums1.size()==i) return nums2[j+k-1];
        // 递归出口：k为1，即求两个数字的最小值
        if(k==1) return min(nums1[i],nums2[j]);

        // 取剩余数组中的k/2长度进行处理
        // num1长度可能不到k/2,min处理取最小长度
        int si=min((int)nums1.size(),i+k/2),sj=j+k/2; //min的size要强转，否则编译不过
        // 核心部分：比较两个数组的第k/2数字，较小值x必然不会是第k小的数字
        //   (两个子数组之和才为k,其中比x小的数必然小于k),可以排除，继续对比剩下的部分
        //   剔除掉的数字个数为k/2，原问题变为找第k-k/2小的数字
        if(nums1[si-1]>nums2[sj-1]) return find(nums1,i,nums2,sj,k-(sj-j));     // k-(sj-j)可替换为k-k/2
        else return find(nums1,si,nums2,j,k-(si-i));    // si可能不足k/2,所以需要减去剩余的
        // 较小值所在数组要剔除元素，需要移动查找起点k/2个位置，另一个数组不变；寻找第k小的数字变为k-k/2(考虑取整的情况)
    }
};
// @lc code=end

