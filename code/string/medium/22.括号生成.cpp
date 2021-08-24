/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 *
 * https://leetcode-cn.com/problems/generate-parentheses/description/
 *
 * algorithms
 * Medium (77.25%)
 * Likes:    1982
 * Dislikes: 0
 * Total Accepted:    329.4K
 * Total Submissions: 426.5K
 * Testcase Example:  '3'
 *
 * 数字 n 代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且 有效的 括号组合。
 * 
 * 有效括号组合需满足：左括号必须以正确的顺序闭合。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：n = 3
 * 输出：["((()))","(()())","(())()","()(())","()()()"]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：n = 1
 * 输出：["()"]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= n <= 8
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    // 1、任意前缀中，'('数量>=')'数量
    // 2、'('、')'数量相等
    // 总数是卡特兰数
    vector<string> ans;
    vector<string> generateParenthesis(int n) {
        dfs(n,0,0,"");
        return ans;
    }

    void dfs(int n, int lc, int rc, string seq) {
        if(lc==n&&rc==n) ans.emplace_back(seq);
        else {
            if(lc<n) dfs(n,lc+1,rc,seq+"(");
            // 这里不能else，在前面递归结束后，进入下面的if，变成类似回调的情况
            if(rc<lc) dfs(n,lc,rc+1,seq+")");
        }
    }
};
// @lc code=end

