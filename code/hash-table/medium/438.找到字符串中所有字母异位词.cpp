/*
 * @lc app=leetcode.cn id=438 lang=cpp
 *
 * [438] 找到字符串中所有字母异位词
 *
 * https://leetcode-cn.com/problems/find-all-anagrams-in-a-string/description/
 *
 * algorithms
 * Medium (51.19%)
 * Likes:    776
 * Dislikes: 0
 * Total Accepted:    147.3K
 * Total Submissions: 272.7K
 * Testcase Example:  '"cbaebabacd"\n"abc"'
 *
 * 给定两个字符串 s 和 p，找到 s 中所有 p 的 异位词 的子串，返回这些子串的起始索引。不考虑答案输出的顺序。
 * 
 * 异位词 指由相同字母重排列形成的字符串（包括相同的字符串）。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 
 * 输入: s = "cbaebabacd", p = "abc"
 * 输出: [0,6]
 * 解释:
 * 起始索引等于 0 的子串是 "cba", 它是 "abc" 的异位词。
 * 起始索引等于 6 的子串是 "bac", 它是 "abc" 的异位词。
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: s = "abab", p = "ab"
 * 输出: [0,1,2]
 * 解释:
 * 起始索引等于 0 的子串是 "ab", 它是 "ab" 的异位词。
 * 起始索引等于 1 的子串是 "ba", 它是 "ab" 的异位词。
 * 起始索引等于 2 的子串是 "ab", 它是 "ab" 的异位词。
 * 
 * 
 * 
 * 
 * 提示:
 * 
 * 
 * 1 <= s.length, p.length <= 3 * 10^4
 * s 和 p 仅包含小写字母
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    // 滑动窗口，用Hash表存储结果
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char, int> cnt;
        vector<int> ans;
        for(auto c:p) {
            cnt[c]++;
        }

        int total = cnt.size();
        for(int i=0,j=0,match=0;j<s.size();++j) {
            if(--cnt[s[j]]==0) {
                ++match;
            }
            // 同步滑动窗口,i+1
            if(j-i==p.size()) {
                // i指向的元素要离开窗口，记录的值要+1
                if(cnt[s[i]]==0) {
                    --match;
                }
                ++cnt[s[i++]];
            }
            if(match==total) {
                ans.emplace_back(i);
            }
        }
        return ans;
    }
};
// @lc code=end

