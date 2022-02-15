/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
 *
 * https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/
 *
 * algorithms
 * Medium (70.10%)
 * Likes:    1421
 * Dislikes: 0
 * Total Accepted:    297.6K
 * Total Submissions: 420.5K
 * Testcase Example:  '[3,9,20,15,7]\n[9,3,15,20,7]'
 *
 * 给定两个整数数组 preorder 和 inorder ，其中 preorder 是二叉树的先序遍历， inorder
 * 是同一棵树的中序遍历，请构造二叉树并返回其根节点。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 
 * 输入: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
 * 输出: [3,9,20,null,null,15,7]
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: preorder = [-1], inorder = [-1]
 * 输出: [-1]
 * 
 * 
 * 
 * 
 * 提示:
 * 
 * 
 * 1 <= preorder.length <= 3000
 * inorder.length == preorder.length
 * -3000 <= preorder[i], inorder[i] <= 3000
 * preorder 和 inorder 均 无重复 元素
 * inorder 均出现在 preorder
 * preorder 保证 为二叉树的前序遍历序列
 * inorder 保证 为二叉树的中序遍历序列
 * 
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
class Solution {
public:
    unordered_map<int,int> pos;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        pos.clear();
        for(int i=0;i<inorder.size();++i) {
            pos[inorder[i]] = i;
        }
        return build(preorder, inorder, 0, preorder.size()-1, 0, inorder.size()-1);
    }

    // 针对preorder[pl,pr],inorder[il,ir]递归构造二叉树，两个区间长度应一致
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int pl, int pr, int il, int ir) {
        if(pl>pr) {
            return nullptr;
        }

        // 前序遍历第一个元素即为当前区间根节点
        auto root = new TreeNode(preorder[pl]);
        int k = pos[root->val];
        root->left = build(preorder, inorder, pl+1, k-il+pl, il, k-1);
        root->right = build(preorder, inorder, k-il+pl+1, pr, k+1, ir);
        return root;
    }
};
// @lc code=end

