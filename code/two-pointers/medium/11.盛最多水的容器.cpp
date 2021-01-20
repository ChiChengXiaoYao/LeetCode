/*
 * @lc app=leetcode.cn id=11 lang=cpp
 *
 * [11] 盛最多水的容器
 *
 * https://leetcode-cn.com/problems/container-with-most-water/description/
 *
 * algorithms
 * Medium (64.54%)
 * Likes:    2127
 * Dislikes: 0
 * Total Accepted:    351.2K
 * Total Submissions: 543.3K
 * Testcase Example:  '[1,8,6,2,5,4,8,3,7]'
 *
 * 给你 n 个非负整数 a1，a2，...，an，每个数代表坐标中的一个点 (i, ai) 。在坐标内画 n 条垂直线，垂直线 i 的两个端点分别为
 * (i, ai) 和 (i, 0) 。找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。
 * 
 * 说明：你不能倾斜容器。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 
 * 
 * 输入：[1,8,6,2,5,4,8,3,7]
 * 输出：49 
 * 解释：图中垂直线代表输入数组 [1,8,6,2,5,4,8,3,7]。在此情况下，容器能够容纳水（表示为蓝色部分）的最大值为 49。
 * 
 * 示例 2：
 * 
 * 
 * 输入：height = [1,1]
 * 输出：1
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：height = [4,3,2,1,4]
 * 输出：16
 * 
 * 
 * 示例 4：
 * 
 * 
 * 输入：height = [1,2,1]
 * 输出：2
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * n = height.length
 * 2 
 * 0 
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    // 草，知道做法如此简单的我无法接受
    /*双指针移动必然得到最优解：
    设最优解下标为a,b；双指针指向下标i,j
    考虑i=a时,b<j，此时j的高度必然小于a的高度(否则a,b对应面积就不是最优解)
    j持续左移,必然经过下标b,被max变量记录
    */
    int maxArea(vector<int>& height) {
        int res=0;
        for(int i=0,j=height.size()-1;i<j;){
            res=max(res,min(height[i],height[j])*(j-i));
            if(height[i]>height[j]) --j;
            else ++i;
        }
        return res;
    }
};
// @lc code=end

