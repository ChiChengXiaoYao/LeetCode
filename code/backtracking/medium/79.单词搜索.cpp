/*
 * @lc app=leetcode.cn id=79 lang=cpp
 *
 * [79] 单词搜索
 *
 * https://leetcode-cn.com/problems/word-search/description/
 *
 * algorithms
 * Medium (46.06%)
 * Likes:    1161
 * Dislikes: 0
 * Total Accepted:    260.8K
 * Total Submissions: 566.2K
 * Testcase Example:  '[["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]\n"ABCCED"'
 *
 * 给定一个 m x n 二维字符网格 board 和一个字符串单词 word 。如果 word 存在于网格中，返回 true ；否则，返回 false
 * 。
 * 
 * 单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word =
 * "ABCCED"
 * 输出：true
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word =
 * "SEE"
 * 输出：true
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word =
 * "ABCB"
 * 输出：false
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * m == board.length
 * n = board[i].length
 * 1 
 * 1 
 * board 和 word 仅由大小写英文字母组成
 * 
 * 
 * 
 * 
 * 进阶：你可以使用搜索剪枝的技术来优化解决方案，使其在 board 更大的情况下可以更快解决问题？
 * 
 */

// @lc code=start
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0;i<board.size();++i) {
            for(int j=0;j<board[0].size();++j) {
                if(dfs(board,word,0,i,j)) {
                    // 结果测试
                    // for(int x=0;x<board.size();++x) {
                    //     for(int y=0;y<board[0].size();++y) {
                    //         cout << board[x][y];
                    //     }
                    //     cout <<endl;
                    // }
                    return true;
                }
            }
        }
        return false;
    }

    const int dx[4]={-1,0,1,0},dy[4]={0,-1,0,1};

    // u:当前搜索word位置；x、y:board所指向的位置
    bool dfs(vector<vector<char>>& board, string word, int u, int x, int y) {
        if(word[u]!=board[x][y]) {
            return false;
        }
        if(word.size()-1==u) {
            return true;
        }

        char t=word[u];
        board[x][y]='*';
        for(int i=0;i<4;++i) {
            int a=x+dx[i],b=y+dy[i];
            if(a<0||b<0||a>=board.size()||b>=board[0].size()||board[a][b]=='*') {
                continue;
            }
            if(dfs(board, word, u+1, a, b)) {
                board[x][y]=t;// 恢复现场
                return true;
            }
        }
        board[x][y]=t;
        return false;
    }
};
// @lc code=end

