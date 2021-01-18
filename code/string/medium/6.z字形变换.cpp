/*
 * @lc app=leetcode.cn id=6 lang=cpp
 *
 * [6] Z 字形变换
 *
 * https://leetcode-cn.com/problems/zigzag-conversion/description/
 *
 * algorithms
 * Medium (49.15%)
 * Likes:    981
 * Dislikes: 0
 * Total Accepted:    206.3K
 * Total Submissions: 418.4K
 * Testcase Example:  '"PAYPALISHIRING"\n3'
 *
 * 将一个给定字符串 s 根据给定的行数 numRows ，以从上往下、从左到右进行 Z 字形排列。
 * 
 * 比如输入字符串为 "PAYPALISHIRING" 行数为 3 时，排列如下：
 * 
 * 
 * P   A   H   N
 * A P L S I I G
 * Y   I   R
 * 
 * 之后，你的输出需要从左往右逐行读取，产生出一个新的字符串，比如："PAHNAPLSIIGYIR"。
 * 
 * 请你实现这个将字符串进行指定行数变换的函数：
 * 
 * 
 * string convert(string s, int numRows);
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：s = "PAYPALISHIRING", numRows = 3
 * 输出："PAHNAPLSIIGYIR"
 * 
 * 示例 2：
 * 
 * 
 * 输入：s = "PAYPALISHIRING", numRows = 4
 * 输出："PINALSIGYAHRPI"
 * 解释：
 * P     I    N
 * A   L S  I G
 * Y A   H R
 * P     I
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：s = "A", numRows = 1
 * 输出："A"
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * s 由英文字母（小写和大写）、',' 和 '.' 组成
 * 1 
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    string convert(string s, int numRows) {
        // 纯找规律
        // 只有一行的时候特判，放在下面会死循环(step=2n-2=0)
        if(numRows==1)    return s;
        string res;
        // 每一行都是等差数列
        for(int i=0;i<numRows;++i){
            // 第0行和第n-1行分别是一个等差数列，首项为0/n-1，公差为2n-2，分别对应i==0/i==n-1
            if(i==0||i==numRows-1){
                for(int j=i;j<s.size();j+=2*numRows-2)
                    res+=s[j];
            // 中间两列是两个等差数列交错，第j行首项为j/2n-j，公差为2n-2，先输出j
            } else {
                for(int j=i,k=2*numRows-2-i;j<s.size()||k<s.size();j+=2*numRows-2,k+=2*numRows-2) {
                    if(j<s.size())  res+=s[j];
                    if(k<s.size())  res+=s[k];
                }
            }
        }
        return res;
    }
};
// @lc code=end

