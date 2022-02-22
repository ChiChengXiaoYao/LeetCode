/*
 * @lc app=leetcode.cn id=28 lang=cpp
 *
 * [28] 实现 strStr()
 *
 * https://leetcode-cn.com/problems/implement-strstr/description/
 *
 * algorithms
 * Easy (40.72%)
 * Likes:    1263
 * Dislikes: 0
 * Total Accepted:    561.8K
 * Total Submissions: 1.4M
 * Testcase Example:  '"hello"\n"ll"'
 *
 * 实现 strStr() 函数。
 * 
 * 给你两个字符串 haystack 和 needle ，请你在 haystack 字符串中找出 needle 字符串出现的第一个位置（下标从 0
 * 开始）。如果不存在，则返回  -1 。
 * 
 * 
 * 
 * 说明：
 * 
 * 当 needle 是空字符串时，我们应当返回什么值呢？这是一个在面试中很好的问题。
 * 
 * 对于本题而言，当 needle 是空字符串时我们应当返回 0 。这与 C 语言的 strstr() 以及 Java 的 indexOf()
 * 定义相符。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：haystack = "hello", needle = "ll"
 * 输出：2
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：haystack = "aaaaa", needle = "bba"
 * 输出：-1
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：haystack = "", needle = ""
 * 输出：0
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 0 
 * haystack 和 needle 仅由小写英文字符组成
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    // KMP算法
    int strStr(string haystack, string needle) {
        if(needle.empty()) {
            return 0;
        }
        // KMP下标从1开始好处理
        string s = ' ' + haystack;
        string p = ' ' + needle;
        // 求next数组
        int m = haystack.size(), n = needle.size();
        vector<int> next(n+1);
        for(int i=2,j=0;i<=n;++i) {
            while(j&&p[i]!=p[j+1]) {
                // 未匹配到，回溯
                j=next[j];
            }
            // 匹配成功，匹配长度+1
            if(p[i]==p[j+1]) {
                ++j;
            }
            next[i]=j;
        }
        // 查找子串
        for(int i=1,j=0;i<=m;++i) {
            while(j&&s[i]!=p[j+1]) {
                j=next[j];
            }
            if(s[i]==p[j+1]) {
                ++j;
            }
            if(j==n) {
                return i-n;
            }
        }
        return -1;
    }
};
// @lc code=end

