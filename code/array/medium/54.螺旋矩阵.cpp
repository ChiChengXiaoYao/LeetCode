/*
 * @lc app=leetcode.cn id=54 lang=cpp
 *
 * [54] 螺旋矩阵
 *
 * https://leetcode-cn.com/problems/spiral-matrix/description/
 *
 * algorithms
 * Medium (47.53%)
 * Likes:    995
 * Dislikes: 0
 * Total Accepted:    226.4K
 * Total Submissions: 467.5K
 * Testcase Example:  '[[1,2,3],[4,5,6],[7,8,9]]'
 *
 * 给你一个 m 行 n 列的矩阵 matrix ，请按照 顺时针螺旋顺序 ，返回矩阵中的所有元素。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：matrix = [[1,2,3],[4,5,6],[7,8,9]]
 * 输出：[1,2,3,6,9,8,7,4,5]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
 * 输出：[1,2,3,4,8,12,11,10,9,5,6,7]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * m == matrix.length
 * n == matrix[i].length
 * 1 
 * -100 
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int m = matrix.size();
        if(!m) {
            return ans;
        }
        int n = matrix[0].size();
        ans.resize(m*n);

        int ax[]={0,1,0,-1},ay[]={1,0,-1,0};
        vector<vector<bool>> check(m, vector<bool>(n));
        for(int i=0,x=0,y=0,d=0;i<ans.size();++i) {
            ans[i] = matrix[x][y];
            check[x][y]=true;

            int nx = x+ax[d],ny = y+ay[d];
            // 调整方向
            if(nx<0||nx>=m||ny<0||ny>=n||check[nx][ny]) {
                d = (d+1)%4;
                nx = x+ax[d],ny = y+ay[d];
            }
            x=nx,y=ny;
        }
        return ans;
    }
};
// @lc code=end

