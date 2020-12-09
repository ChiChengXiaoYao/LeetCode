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
    // DP专场
    /*
        用dp[i][j]表示到坐标(i,j)共有多少条不同的路径，则最终需要求dp[m-1][n-1]
        只能向右/向下前进，则dp[i][j]=dp[i-1][j](上方)+dp[i][j-1](左侧)
        对于边界，dp[i][0]=dp[0][j]=1

        整理：
        状态定义：
            dp[i][j]表示到坐标(i,j)共有多少条不同的路径
        状态转移方程：
            dp[i][j]=dp[i-1][j]+dp[i][j-1]
        状态初始化(边界值)：
            dp[i][0]=dp[0][j]=1
    */
    // 未优化：二维数组100%/5.25%
    // int uniquePaths(int m, int n) {
    //     vector<vector<int>> dp(m,vector<int>(n,1));

    //     for(int i=1;i<m;++i)
    //     {
    //         for(int j=1;j<n;++j)
    //         {
    //             dp[i][j]=dp[i-1][j]+dp[i][j-1];
    //         }
    //     }
    //     return dp[m-1][n-1];
    // }

    // 优化空间：一维数组*2 100%/41.46%
    // 每次只需要当前行和前一行的数据
    // int uniquePaths(int m, int n) {
    //     vector<int> pre(n,1),cur(n,1);

    //     for(int i=1;i<m;++i)
    //     {
    //         for(int j=1;j<n;++j)
    //         {
    //             cur[j]=pre[j]+cur[j-1];
    //         }
    //         swap(pre,cur);
    //     }
    //     return pre[n-1];
    // }

    // 优化空间：一维数组 100%/35.13%
    // 每次只是用上一行的j:pre[j]
    // 实际上每次只用到它左边和上边的值，左边的值在上轮更新后不变，上边的值在本次运算结束后被覆盖
    int uniquePaths(int m, int n) {
        vector<int> dp(n,1);

        for(int i=1;i<m;++i)
        {
            for(int j=1;j<n;++j)
            {
                dp[j]+=dp[j-1];
            }
        }
        return dp[n-1];
    }
};
// @lc code=end

