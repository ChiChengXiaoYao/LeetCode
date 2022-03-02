/*
 * @lc app=leetcode.cn id=131 lang=cpp
 *
 * [131] 分割回文串
 *
 * https://leetcode-cn.com/problems/palindrome-partitioning/description/
 *
 * algorithms
 * Medium (72.45%)
 * Likes:    1009
 * Dislikes: 0
 * Total Accepted:    164.3K
 * Total Submissions: 226.3K
 * Testcase Example:  '"aab"'
 *
 * 给你一个字符串 s，请你将 s 分割成一些子串，使每个子串都是 回文串 。返回 s 所有可能的分割方案。
 * 
 * 回文串 是正着读和反着读都一样的字符串。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：s = "aab"
 * 输出：[["a","a","b"],["aa","b"]]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：s = "a"
 * 输出：[["a"]]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * s 仅由小写英文字母组成
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<vector<bool>> f;
    vector<string> path;
    vector<vector<string>> ans;
    vector<vector<string>> partition(string s) {
        int n=s.size();
        f=vector<vector<bool>>(n,vector<bool>(n));
        // 预处理 判断子串[i,j]是否是回文串
        for(int j=0;j<n;++j) {
            for(int i=0;i<=j;++i) {
                if(i==j) {
                    f[i][j]=true;
                }
                else if(s[i]==s[j]) {
                    // 防止越界
                    if(i+1>j-1||f[i+1][j-1]) {
                        f[i][j]=true;
                    }
                }
            }
        }

        dfs(s,0);
        return ans;
    }

    void dfs(string& s, int n) {
        if(n==s.size()) {
            ans.push_back(path);
            return;
        }

        for(int i=n;i<s.size();++i) {
            // 下一段，从n到i是回文串
            if(f[n][i]) {
                // 将这一段存放进path中，递归进入下一层
                path.push_back(s.substr(n,i-n+1));
                dfs(s, i+1);
                // 无论符不符合答案，都需要将本次的结果删掉
                path.pop_back();
            }
        }
    }
};
// @lc code=end

