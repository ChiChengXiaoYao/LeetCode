/*
 * @lc app=leetcode.cn id=279 lang=cpp
 *
 * [279] 完全平方数
 *
 * https://leetcode-cn.com/problems/perfect-squares/description/
 *
 * algorithms
 * Medium (62.63%)
 * Likes:    1234
 * Dislikes: 0
 * Total Accepted:    238.6K
 * Total Submissions: 372.8K
 * Testcase Example:  '12'
 *
 * 给你一个整数 n ，返回 和为 n 的完全平方数的最少数量 。
 * 
 * 完全平方数 是一个整数，其值等于另一个整数的平方；换句话说，其值等于一个整数自乘的积。例如，1、4、9 和 16 都是完全平方数，而 3 和 11
 * 不是。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：n = 12
 * 输出：3 
 * 解释：12 = 4 + 4 + 4
 * 
 * 示例 2：
 * 
 * 
 * 输入：n = 13
 * 输出：2
 * 解释：13 = 4 + 9
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= n <= 10^4
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    // [拉格朗日四平方和定理](https://en.wikipedia.org/wiki/Lagrange%27s_four-square_theorem):
    // 答案必然为1/2/3/4
    int numSquares(int n) {
        // 自身就是完全平方数
        if(check(n)) {
            return 1;
        }

        // 是两个完全平方数之和 i<n/i可以防止越界
        for(int i=1; i<n/i;++i) {
            // 检查n-i*i后的值是否是完全平方数，即i*i+x*x==n
            if(check(n-i*i)) {
                return 2;
            }
        }

        // [勒让德三平方和定理](https://en.wikipedia.org/wiki/Legendre%27s_three-square_theorem):
        // 当且仅当 n!=4^a * (8b+7) 时，可以表示为3个整数(ab均为非负整数)
        while(n%4==0) {
            n>>=2;
        }
        if(n%8!=7) {
            return 3;
        }
        return 4;
    }

    bool check(int n) {
        int x = std::sqrt(n);
        return x*x == n;
    }
};
// @lc code=end

