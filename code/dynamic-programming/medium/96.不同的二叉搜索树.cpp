/*
 * @lc app=leetcode.cn id=96 lang=cpp
 *
 * [96] 不同的二叉搜索树
 *
 * https://leetcode-cn.com/problems/unique-binary-search-trees/description/
 *
 * algorithms
 * Medium (69.97%)
 * Likes:    1517
 * Dislikes: 0
 * Total Accepted:    194.6K
 * Total Submissions: 278.2K
 * Testcase Example:  '3'
 *
 * 给你一个整数 n ，求恰由 n 个节点组成且节点值从 1 到 n 互不相同的 二叉搜索树 有多少种？返回满足题意的二叉搜索树的种数。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：n = 3
 * 输出：5
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：n = 1
 * 输出：1
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    /*
    假设n个节点存在二叉排序树的个数是G(n)，令f(i)为以i为根的二叉搜索树的个数，则
    G(n)=f(1)+f(2)+f(3)+f(4)+...+f(n)

    当i为根节点时，其左子树节点个数为i-1个，右子树节点为n-i，则
    f(i)=G(i-1)*G(n-i)

    综合两个公式可以得到卡特兰数公式(C(2n,n)/(n+1))
    G(n)=G(0)*G(n-1)+G(1)*G(n-2)+...+G(n-1)*G(0)
    */
    int numTrees(int n) {
        vector<int> dp(n+1);
        dp[0]=1;

        for(int i=1;i<=n;++i) {
            for(int j=1;j<=i;++j) {
                // 计算G[i]+=G[j-1]*G[i-j]
                dp[i] += dp[j-1]*dp[i-j];
            }
        }
        return dp[n];
    }
};
// @lc code=end

