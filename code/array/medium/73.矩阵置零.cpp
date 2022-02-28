/*
 * @lc app=leetcode.cn id=73 lang=cpp
 *
 * [73] 矩阵置零
 *
 * https://leetcode-cn.com/problems/set-matrix-zeroes/description/
 *
 * algorithms
 * Medium (59.73%)
 * Likes:    662
 * Dislikes: 0
 * Total Accepted:    163.6K
 * Total Submissions: 266.9K
 * Testcase Example:  '[[1,1,1],[1,0,1],[1,1,1]]'
 *
 * 给定一个 m x n 的矩阵，如果一个元素为 0 ，则将其所在行和列的所有元素都设为 0 。请使用 原地 算法。
 * 
 * 
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：matrix = [[1,1,1],[1,0,1],[1,1,1]]
 * 输出：[[1,0,1],[0,0,0],[1,0,1]]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
 * 输出：[[0,0,0,0],[0,4,5,0],[0,3,1,0]]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * m == matrix.length
 * n == matrix[0].length
 * 1 <= m, n <= 200
 * -2^31 <= matrix[i][j] <= 2^31 - 1
 * 
 * 
 * 
 * 
 * 进阶：
 * 
 * 
 * 一个直观的解决方案是使用  O(mn) 的额外空间，但这并不是一个好的解决方案。
 * 一个简单的改进方案是使用 O(m + n) 的额外空间，但这仍然不是最好的解决方案。
 * 你能想出一个仅使用常量空间的解决方案吗？
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        // 用第一行和第一列存储剩余m-1*n-1的矩阵是否需要置零
        // 再用两个额外的变量存储第一行和第一列
        int front_x=1,front_y=1;    // 1为不用置零
        for(int x=0;x<matrix.size();++x) {
            if(!matrix[x][0]) {
                front_x=0;
                break;
            }
        }
        for(int y=0;y<matrix[0].size();++y) {
            if(!matrix[0][y]) {
                front_y=0;
                break;
            }
        }
        // 将需要置0的行和列标记在首行和首列中
        for(int x=1;x<matrix.size();++x) {
            for(int y=1;y<matrix[0].size();++y) {
                if(!matrix[x][y]) {
                    matrix[x][0]=0;
                    matrix[0][y]=0;
                }
            }
        }

        // 第x行为0，则将其全部置为0
        for(int x=1;x<matrix.size();++x) {
            if(!matrix[x][0]) {
                for(int y=1;y<matrix[0].size();++y) {
                    matrix[x][y]=0;
                }
            }
            
        }
        // 第y列为0，则将其全部置为0
        for(int y=1;y<matrix[0].size();++y) {
            if(!matrix[0][y]) {
                for(int x=1;x<matrix.size();++x) {
                    matrix[x][y]=0;
                }
            }
        }

        // 首行首列置为零
        if(!front_x) {
            for(int x=0;x<matrix.size();++x) {
                matrix[x][0] = 0;
            }
        }
        if(!front_y) {
            for(int y=0;y<matrix[0].size();++y) {
                matrix[0][y] = 0;
            }
        }
    }
};
// @lc code=end

