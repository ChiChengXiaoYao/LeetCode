/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
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

