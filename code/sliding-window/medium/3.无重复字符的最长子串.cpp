/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 *
 * https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/description/
 *
 * algorithms
 * Medium (35.66%)
 * Likes:    4390
 * Dislikes: 0
 * Total Accepted:    680.6K
 * Total Submissions: 1.9M
 * Testcase Example:  '"abcabcbb"'
 *
 * 给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。
 * 
 * 示例 1:
 * 
 * 输入: "abcabcbb"
 * 输出: 3 
 * 解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
 * 
 * 
 * 示例 2:
 * 
 * 输入: "bbbbb"
 * 输出: 1
 * 解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
 * 
 * 
 * 示例 3:
 * 
 * 输入: "pwwkew"
 * 输出: 3
 * 解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
 * 请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        /// 滑动窗口
        /// 没有重复字母：滑动右边界end
        /// 出现重复字母：滑动左边界start
        // 开一个字符大小的数组
        vector<int> dict(128,-1);

        // 左开右闭,(start,end]
        int maxLen=0,start=-1;
        for(int end=0;end<s.size();++end){
            // dict[s[end]]查找当前字母出现的最新位置
            // 如果start更新，则说明当前字母已经出现过，
            // 则start变为最新出现的位置（去除重复字母）
            start=max(start,dict[s[end]]);
            // 更新当前字母的最新位置
            dict[s[end]]=end;
            maxLen=max(maxLen,end-start);
        }
        return maxLen;
    }
};
// @lc code=end

