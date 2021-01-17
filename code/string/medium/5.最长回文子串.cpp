/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 *
 * https://leetcode-cn.com/problems/longest-palindromic-substring/description/
 *
 * algorithms
 * Medium (32.50%)
 * Likes:    3104
 * Dislikes: 0
 * Total Accepted:    458.5K
 * Total Submissions: 1.4M
 * Testcase Example:  '"babad"'
 *
 * 给你一个字符串 s，找到 s 中最长的回文子串。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：s = "babad"
 * 输出："bab"
 * 解释："aba" 同样是符合题意的答案。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：s = "cbbd"
 * 输出："bb"
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：s = "a"
 * 输出："a"
 * 
 * 
 * 示例 4：
 * 
 * 
 * 输入：s = "ac"
 * 输出："a"
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * s 仅由数字和英文字母（大写和/或小写）组成
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    // 时间复杂度O(n²)
    string longestPalindrome(string s) {
        string res;
        for(int i=0;i<s.size();++i){
            // 奇数回文串
            int l=i-1,r=i+1;
            while(l>=0&&r<s.size()&&s[l]==s[r]) --l,++r;
            // 此时s[l]!=s[r] 长度r-l+1-2
            if(res.size()<r-l-1)    res=s.substr(l+1,r-l-1); // substr索引左闭右开[,)

            // 偶数回文串
            l=i,r=i+1;
            while(l>=0&&r<s.size()&&s[l]==s[r]) --l,++r;
            if(res.size()<r-l-1)    res=s.substr(l+1,r-l-1);
        }
        return res;
    }
};
// @lc code=end

