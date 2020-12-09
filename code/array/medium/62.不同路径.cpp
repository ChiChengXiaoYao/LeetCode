/*
 * @lc app=leetcode.cn id=62 lang=cpp
 *
 * [62] 不同路径
 *
 * https://leetcode-cn.com/problems/unique-paths/description/
 *
 * algorithms
 * Medium (62.25%)
 * Likes:    692
 * Dislikes: 0
 * Total Accepted:    149.2K
 * Total Submissions: 239.6K
 * Testcase Example:  '3\n7'
 *
 * 一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为“Start” ）。
 * 
 * 机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为“Finish”）。
 * 
 * 问总共有多少条不同的路径？
 * 
 * 
 * 
 * 例如，上图是一个7 x 3 的网格。有多少可能的路径？
 * 
 * 
 * 
 * 示例 1:
 * 
 * 输入: m = 3, n = 2
 * 输出: 3
 * 解释:
 * 从左上角开始，总共有 3 条路径可以到达右下角。
 * 1. 向右 -> 向右 -> 向下
 * 2. 向右 -> 向下 -> 向右
 * 3. 向下 -> 向右 -> 向右
 * 
 * 
 * 示例 2:
 * 
 * 输入: m = 7, n = 3
 * 输出: 28
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= m, n <= 100
 * 题目数据保证答案小于等于 2 * 10 ^ 9
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    /*
        m宽*n高，则必然有m-1次向右，n-1向下操作，共m+n-2次操作
        转换为数学问题即为组合问题：m-1个A和n-1个B共有多少种组合方式
        即    m-1       n-1
            C m+n-2 = C m+n-2
    */
    int uniquePaths(int m, int n) {
        int sum=m+n-2;
        m=min(m,n)-1;
        long result=1;
        // e.g:sum=7,m=3
        // 5/1 * 6/2 * 7/3
        for(int i = 1; i<= m; i++)
        {
            result = result * (sum - m + i)/i;
        }
        return result;
    }
};
// @lc code=end

