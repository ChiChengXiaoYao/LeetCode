/*
 * @lc app=leetcode.cn id=647 lang=cpp
 *
 * [647] 回文子串
 *
 * https://leetcode-cn.com/problems/palindromic-substrings/description/
 *
 * algorithms
 * Medium (65.45%)
 * Likes:    776
 * Dislikes: 0
 * Total Accepted:    147.1K
 * Total Submissions: 222.6K
 * Testcase Example:  '"abc"'
 *
 * 给你一个字符串 s ，请你统计并返回这个字符串中 回文子串 的数目。
 * 
 * 回文字符串 是正着读和倒过来读一样的字符串。
 * 
 * 子字符串 是字符串中的由连续字符组成的一个序列。
 * 
 * 具有不同开始位置或结束位置的子串，即使是由相同的字符组成，也会被视作不同的子串。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：s = "abc"
 * 输出：3
 * 解释：三个回文子串: "a", "b", "c"
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：s = "aaa"
 * 输出：6
 * 解释：6个回文子串: "a", "a", "a", "aa", "aa", "aaa"
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= s.length <= 1000
 * s 由小写英文字母组成
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    // 遍历枚举，通过更改中心点所在位置进行枚举
    int countSubstrings(string s) {
        int ans=0;
        // 中心点所在位置
        for(int i=0;i<s.size();++i) {
            // 回文串为奇数
            for(int j=i,k=i;j>=0&&k<s.size();--j,++k) {
                if(s[j]!=s[k]) {
                    break;
                }
                ++ans;
            }

            // 回文串为偶数
            for(int j=i,k=i+1;j>=0&&k<s.size();--j,++k) {
                if(s[j]!=s[k]) {
                    break;
                }
                ++ans;
            }
        }
        return ans;
    }
};
// @lc code=end

