/*
 * @lc app=leetcode.cn id=290 lang=cpp
 *
 * [290] 单词规律
 *
 * https://leetcode-cn.com/problems/word-pattern/description/
 *
 * algorithms
 * Easy (43.91%)
 * Likes:    244
 * Dislikes: 0
 * Total Accepted:    45.7K
 * Total Submissions: 101.7K
 * Testcase Example:  '"abba"\n"dog cat cat dog"'
 *
 * 给定一种规律 pattern 和一个字符串 str ，判断 str 是否遵循相同的规律。
 * 
 * 这里的 遵循 指完全匹配，例如， pattern 里的每个字母和字符串 str 中的每个非空单词之间存在着双向连接的对应规律。
 * 
 * 示例1:
 * 
 * 输入: pattern = "abba", str = "dog cat cat dog"
 * 输出: true
 * 
 * 示例 2:
 * 
 * 输入:pattern = "abba", str = "dog cat cat fish"
 * 输出: false
 * 
 * 示例 3:
 * 
 * 输入: pattern = "aaaa", str = "dog cat cat dog"
 * 输出: false
 * 
 * 示例 4:
 * 
 * 输入: pattern = "abba", str = "dog dog dog dog"
 * 输出: false
 * 
 * 说明:
 * 你可以假设 pattern 只包含小写字母， str 包含了由单个空格分隔的小写字母。    
 * 
 */

// @lc code=start
class Solution {
public:
    // 双Hash。一一对应，集合论中称为【双射】
    bool wordPattern(string pattern, string s) {
        //字符串到索引i的map以及匹配串到索引i的map
        unordered_map<string,int> strInt;
        unordered_map<char,int> charInt;
        istringstream in(s);

        int i=0,n=pattern.size();
        for(string word;in >> word; ++i){
            // 不符合条件
            // i==n:说明长度不等了，word过多，必然false
            // strInt[word]!=charInt[pattern[i]]:word的索引与对应匹配串的索引不同，说明一一对应关系失败，false
            if(i==n||strInt[word]!=charInt[pattern[i]])
                return false;
            // 设置一个唯一索引，不能从0开始，因为下标运算后，没有值的默认为0！！！！！
            strInt[word]=charInt[pattern[i]] = i+1;
        }
        // 长度相同时，跳出循环后i与n相等，此时才为true
        return i==n;
    }
};
// @lc code=end

