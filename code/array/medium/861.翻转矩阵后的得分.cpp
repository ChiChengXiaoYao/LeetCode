/*
 * @lc app=leetcode.cn id=861 lang=cpp
 *
 * [861] 翻转矩阵后的得分
 *
 * https://leetcode-cn.com/problems/score-after-flipping-matrix/description/
 *
 * algorithms
 * Medium (74.60%)
 * Likes:    87
 * Dislikes: 0
 * Total Accepted:    6.4K
 * Total Submissions: 8.6K
 * Testcase Example:  '[[0,0,1,1],[1,0,1,0],[1,1,0,0]]'
 *
 * 有一个二维矩阵 A 其中每个元素的值为 0 或 1 。
 * 
 * 移动是指选择任一行或列，并转换该行或列中的每一个值：将所有 0 都更改为 1，将所有 1 都更改为 0。
 * 
 * 在做出任意次数的移动后，将该矩阵的每一行都按照二进制数来解释，矩阵的得分就是这些数字的总和。
 * 
 * 返回尽可能高的分数。
 * 
 * 
 * 
 * 
 * 
 * 
 * 示例：
 * 
 * 输入：[[0,0,1,1],[1,0,1,0],[1,1,0,0]]
 * 输出：39
 * 解释：
 * 转换为 [[1,1,1,1],[1,0,0,1],[1,1,1,1]]
 * 0b1111 + 0b1001 + 0b1111 = 15 + 9 + 15 = 39
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= A.length <= 20
 * 1 <= A[0].length <= 20
 * A[i][j] 是 0 或 1
 * 
 * 
 */

// @lc code=start
class Solution
{
public:
    int matrixScore(vector<vector<int>> &A)
    {
        // 以权值考虑，高位权值最大，所以通过行翻转，将第一列翻转为全1
        // 后续只进行列翻转，实际上翻转后0和1的数量互换，因此取二者最大值 假装翻转即可
        // 实际代码中，第一列也可以不进行处理，根据第一列的值，统计0和1时翻转即可
        int rows = A.size();
        int columns = A[0].size();
        int sum = 0;
        for (int i = 0; i < columns; ++i)
        {
            int zeroCount = 0;
            for (int j = 0; j < rows; ++j)
            {
                // 首列为1，则统计0的个数
                // 首列为0，则统计1的个数(翻转后即为0)
                zeroCount += A[j][0] ^ A[j][i];
            }
            // 取0和1中的最大值
            zeroCount = max(zeroCount, rows - zeroCount);
            sum += zeroCount << (columns - i - 1);
        }
        return sum;
    }
};
// @lc code=end
