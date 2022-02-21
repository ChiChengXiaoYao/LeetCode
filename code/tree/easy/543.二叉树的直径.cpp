/*
 * @lc app=leetcode.cn id=543 lang=cpp
 *
 * [543] 二叉树的直径
 *
 * https://leetcode-cn.com/problems/diameter-of-binary-tree/description/
 *
 * algorithms
 * Easy (54.37%)
 * Likes:    913
 * Dislikes: 0
 * Total Accepted:    179.4K
 * Total Submissions: 320K
 * Testcase Example:  '[1,2,3,4,5]'
 *
 * 给定一棵二叉树，你需要计算它的直径长度。一棵二叉树的直径长度是任意两个结点路径长度中的最大值。这条路径可能穿过也可能不穿过根结点。
 * 
 * 
 * 
 * 示例 :
 * 给定二叉树
 * 
 * ⁠         1
 * ⁠        / \
 * ⁠       2   3
 * ⁠      / \     
 * ⁠     4   5    
 * 
 * 
 * 返回 3, 它的长度是路径 [4,2,1,3] 或者 [5,2,1,3]。
 * 
 * 
 * 
 * 注意：两结点之间的路径长度是以它们之间边的数目表示。
 * 
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
// TODO 对应视频仍有相关题目
class Solution {
public:
    // 另一种做法：对于一棵树（不局限于二叉树）：存储为无向图进行两次DFS搜索：
    // 1、任意选择一个点A为起点，DFS找到距离最远的点B
    // 2、以点B为起点再次进行DFS
    int ans = 0;
    int diameterOfBinaryTree(TreeNode* root) {
        // 枚举每个点，求该点左子树与右子树最大值高度之和
        dfs(root);
        return ans;
    }

    int dfs(TreeNode* root) {
        if(!root) {
            return 0;
        }
        int left = dfs(root->left);
        int right = dfs(root->right);
        ans = max(ans,left+right);
        // 返回上一级，子树高度+1
        return max(left,right)+1;
    }
};
// @lc code=end

