/*
 * @lc app=leetcode.cn id=501 lang=cpp
 *
 * [501] 二叉搜索树中的众数
 *
 * https://leetcode-cn.com/problems/find-mode-in-binary-search-tree/description/
 *
 * algorithms
 * Easy (45.96%)
 * Likes:    148
 * Dislikes: 0
 * Total Accepted:    19.2K
 * Total Submissions: 41.7K
 * Testcase Example:  '[1,null,2,2]'
 *
 * 给定一个有相同值的二叉搜索树（BST），找出 BST 中的所有众数（出现频率最高的元素）。
 * 
 * 假定 BST 有如下定义：
 * 
 * 
 * 结点左子树中所含结点的值小于等于当前结点的值
 * 结点右子树中所含结点的值大于等于当前结点的值
 * 左子树和右子树都是二叉搜索树
 * 
 * 
 * 例如：
 * 给定 BST [1,null,2,2],
 * 
 * ⁠  1
 * ⁠   \
 * ⁠    2
 * ⁠   /
 * ⁠  2
 * 
 * 
 * 返回[2].
 * 
 * 提示：如果众数超过1个，不需考虑输出顺序
 * 
 * 进阶：你可以不使用额外的空间吗？（假设由递归产生的隐式调用栈的开销不被计算在内）
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
    vector<int> result;
    int max = 0, pre = INT_MIN, cur;
public:
    void inorder(TreeNode* root){
        // BST树中序有序
        // 记录当前众数，将值存入vector中
        if(!root)   return;

        findMode(root->left);
        // 当前值统计
        if(root->val==pre)  ++cur;
        else    cur=1;

        if(max==cur)    result.push_back(root->val);
        if(max<cur){
            ++max;
            result.clear();
            result.push_back(root->val);
        }
        pre = root->val;

        findMode(root->right);
    }

    vector<int> findMode(TreeNode* root) {
        inorder(root);
        return result;
    }
};
// @lc code=end

