/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 *
 * https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/description/
 *
 * algorithms
 * Medium (35.97%)
 * Likes:    4822
 * Dislikes: 0
 * Total Accepted:    794.3K
 * Total Submissions: 2.2M
 * Testcase Example:  '"abcabcbb"'
 *
 * 给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 
 * 输入: s = "abcabcbb"
 * 输出: 3 
 * 解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: s = "bbbbb"
 * 输出: 1
 * 解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
 * 
 * 
 * 示例 3:
 * 
 * 
 * 输入: s = "pwwkew"
 * 输出: 3
 * 解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
 * 请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
 * 
 * 
 * 示例 4:
 * 
 * 
 * 输入: s = ""
 * 输出: 0
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 0 
 * s 由英文字母、数字、符号和空格组成
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    // 思路：要在所有子串中寻找最大值
    // [i,j]为无重复子串时，若[i,j+1]出现重复，则[i-n,j+1](n≥0)必然重复，i只能右移
    // 保证两个端点只会向右移动，可使用双指针
    int lengthOfLongestSubstring(string s) {
        // 统计每个字符出现的次数
        unordered_map<char,int> heap;
        int res = 0;
        for(int i = 0,j=0;i<s.size();++i) {
            ++heap[s[i]];
            // 出现重复，必然是新加入的元素重复
            while (heap[s[i]]>1) {
                // j要右移一位(j++)，则删除对应的字符(heap[s[j]]--)
                heap[s[j++]]--;
            }
            // 当前得到一个局部解，更新最大值
            res = max(res,i-j+1);
        }
        return res;
    }
};
// @lc code=end

