/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 *
 * https://leetcode-cn.com/problems/valid-parentheses/description/
 *
 * algorithms
 * Easy (43.04%)
 * Likes:    1865
 * Dislikes: 0
 * Total Accepted:    416.3K
 * Total Submissions: 967.2K
 * Testcase Example:  '"()"'
 *
 * 给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。
 * 
 * 有效字符串需满足：
 * 
 * 
 * 左括号必须用相同类型的右括号闭合。
 * 左括号必须以正确的顺序闭合。
 * 
 * 
 * 注意空字符串可被认为是有效字符串。
 * 
 * 示例 1:
 * 
 * 输入: "()"
 * 输出: true
 * 
 * 
 * 示例 2:
 * 
 * 输入: "()[]{}"
 * 输出: true
 * 
 * 
 * 示例 3:
 * 
 * 输入: "(]"
 * 输出: false
 * 
 * 
 * 示例 4:
 * 
 * 输入: "([)]"
 * 输出: false
 * 
 * 
 * 示例 5:
 * 
 * 输入: "{[]}"
 * 输出: true
 * 
 */

// @lc code=start
class Solution {
public:
    bool isValid(string s) {
        stack<char> str;
        for(char& c : s){
            switch (c)
            {
            case '(':
            case '[':
            case '{':
                str.push(c);
                break;
            // 确定非空才可调用top和pop函数(为空表示右括号多)
            case ')': 
                if(str.empty()||str.top()!='(') return false;
                else str.pop();break;
            case ']':
                if(str.empty()||str.top()!='[') return false;
                else str.pop();break;
            case '}':
                if(str.empty()||str.top()!='{') return false;
                else str.pop();break;
            default:
                break;
            }
        }
        // 跳出循环说明：
        // 1、全部验证过，且全部对应
        // 2、左括号有多，不要遗漏这种情况
        return str.empty();
    }
};
// @lc code=end

