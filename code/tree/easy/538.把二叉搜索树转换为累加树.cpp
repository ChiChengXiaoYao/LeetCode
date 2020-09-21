/*
 * @lc app=leetcode.cn id=538 lang=cpp
 *
 * [538] 把二叉搜索树转换为累加树
 *
 * https://leetcode-cn.com/problems/convert-bst-to-greater-tree/description/
 *
 * algorithms
 * Easy (64.04%)
 * Likes:    390
 * Dislikes: 0
 * Total Accepted:    61.7K
 * Total Submissions: 96.4K
 * Testcase Example:  '[5,2,13]'
 *
 * 给定一个二叉搜索树（Binary Search Tree），把它转换成为累加树（Greater
 * Tree)，使得每个节点的值是原来的节点值加上所有大于它的节点值之和。
 * 
 * 
 * 
 * 例如：
 * 
 * 输入: 原始二叉搜索树:
 * ⁠             5
 * ⁠           /   \
 * ⁠          2     13
 * 
 * 输出: 转换为累加树:
 * ⁠            18
 * ⁠           /   \
 * ⁠         20     13
 * 
 * 
 * 
 * 
 * 注意：本题和 1038:
 * https://leetcode-cn.com/problems/binary-search-tree-to-greater-sum-tree/ 相同
 * 
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
// 统计累加值(不要用static写在convertBST里面，后面每次测试不会重置)
int sum = 0;
public:
    TreeNode* convertBST(TreeNode* root) {
        // 右 根 左的顺序遍历，累加即可
        if(root != NULL) {
            // 找到右下角的值，+0后开始与其它节点累加
            convertBST(root->right);
            
            root->val += sum;
            sum = root->val;
            
            convertBST(root->left);
            // 想清楚返回值的地方
            return root;
        }
        return NULL;
    }
};
// @lc code=end