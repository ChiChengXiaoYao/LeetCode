/*
 * @lc app=leetcode.cn id=538 lang=cpp
 *
 * [538] 把二叉搜索树转换为累加树
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

