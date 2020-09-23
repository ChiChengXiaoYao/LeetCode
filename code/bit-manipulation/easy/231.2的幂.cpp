/*
 * @lc app=leetcode.cn id=231 lang=cpp
 *
 * [231] 2的幂
 *
 * https://leetcode-cn.com/problems/power-of-two/description/
 *
 * algorithms
 * Easy (48.60%)
 * Likes:    245
 * Dislikes: 0
 * Total Accepted:    80K
 * Total Submissions: 164.5K
 * Testcase Example:  '1'
 *
 * 给定一个整数，编写一个函数来判断它是否是 2 的幂次方。
 * 
 * 示例 1:
 * 
 * 输入: 1
 * 输出: true
 * 解释: 2^0 = 1
 * 
 * 示例 2:
 * 
 * 输入: 16
 * 输出: true
 * 解释: 2^4 = 16
 * 
 * 示例 3:
 * 
 * 输入: 218
 * 输出: false
 * 
 */

// @lc code=start
class Solution {
public:
    bool isPowerOfTwo(int n) {
        // 二进制表示下，2的倍数表示形式为100000.....
        // 与011111进行与操作结果应该为0
        // 进行异或操作结果为1(不具有唯一性)
        // n为2的倍数时，n-1为上述形式
        // n<=0时要注意单独处理
        // 尽量不要用分支
        //return  (n>0) ? !(n&(n-1)) : false;
        return (n>0) && !(n&(n-1));
        
    }
};
// @lc code=end

