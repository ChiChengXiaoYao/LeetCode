/*
 * @lc app=leetcode.cn id=118 lang=cpp
 *
 * [118] 杨辉三角
 *
 * https://leetcode-cn.com/problems/pascals-triangle/description/
 *
 * algorithms
 * Easy (67.83%)
 * Likes:    417
 * Dislikes: 0
 * Total Accepted:    135.4K
 * Total Submissions: 195.4K
 * Testcase Example:  '5'
 *
 * 给定一个非负整数 numRows，生成杨辉三角的前 numRows 行。
 * 
 * 
 * 
 * 在杨辉三角中，每个数是它左上方和右上方的数的和。
 * 
 * 示例:
 * 
 * 输入: 5
 * 输出:
 * [
 * ⁠    [1],
 * ⁠   [1,1],
 * ⁠  [1,2,1],
 * ⁠ [1,3,3,1],
 * ⁠[1,4,6,4,1]
 * ]
 * 
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> ret;
        for (int i = 0; i < numRows; ++i)
        {
            // 第i行共有i+1个元素
            vector<int> row(i + 1, 1);
            for (int j = 1; j < i; ++j)
            {
                row[j] = ret[i - 1][j] + ret[i - 1][j - 1];
            }
            ret.push_back(move(row));
        }
        return move(ret);
    }
};
// @lc code=end
