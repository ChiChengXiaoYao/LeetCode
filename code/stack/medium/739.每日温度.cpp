/*
 * @lc app=leetcode.cn id=739 lang=cpp
 *
 * [739] 每日温度
 *
 * https://leetcode-cn.com/problems/daily-temperatures/description/
 *
 * algorithms
 * Medium (68.44%)
 * Likes:    1003
 * Dislikes: 0
 * Total Accepted:    242.8K
 * Total Submissions: 354.7K
 * Testcase Example:  '[73,74,75,71,69,72,76,73]'
 *
 * 请根据每日 气温 列表 temperatures ，请计算在每一天需要等几天才会有更高的温度。如果气温在这之后都不会升高，请在该位置用 0 来代替。
 * 
 * 示例 1:
 * 
 * 
 * 输入: temperatures = [73,74,75,71,69,72,76,73]
 * 输出: [1,1,4,2,1,1,0,0]
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: temperatures = [30,40,50,60]
 * 输出: [1,1,1,0]
 * 
 * 
 * 示例 3:
 * 
 * 
 * 输入: temperatures = [30,60,90]
 * 输出: [1,1,0]
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * 30 
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    // 单调栈模板题
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> stk;
        vector<int> res(temperatures.size());
        // 查数组右边(即栈内)比自身大的数
        // 从右边开始进栈，栈内单调递减(栈底到栈顶)
        for(int i=temperatures.size()-1;i>=0;--i) {
            // 新取的数>=栈顶
            while(stk.size()&&temperatures[i]>=temperatures[stk.top()]) {
                stk.pop();
            }
            if(stk.size()) {
                res[i]=stk.top()-i;
            }
            stk.push(i);
        }
        return res;
    }
};
// @lc code=end

