/*
 * @lc app=leetcode.cn id=236 lang=cpp
 *
 * [236] 二叉树的最近公共祖先
 *
 * https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-tree/description/
 *
 * algorithms
 * Medium (67.62%)
 * Likes:    1535
 * Dislikes: 0
 * Total Accepted:    311.4K
 * Total Submissions: 454.5K
 * Testcase Example:  '[3,5,1,6,2,0,8,null,null,7,4]\n5\n1'
 *
 * 给定一个二叉树, 找到该树中两个指定节点的最近公共祖先。
 * 
 * 百度百科中最近公共祖先的定义为：“对于有根树 T 的两个节点 p、q，最近公共祖先表示为一个节点 x，满足 x 是 p、q 的祖先且 x
 * 的深度尽可能大（一个节点也可以是它自己的祖先）。”
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
 * 输出：3
 * 解释：节点 5 和节点 1 的最近公共祖先是节点 3 。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
 * 输出：5
 * 解释：节点 5 和节点 4 的最近公共祖先是节点 5 。因为根据定义最近公共祖先节点可以为节点本身。
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：root = [1,2], p = 1, q = 2
 * 输出：1
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 树中节点数目在范围 [2, 10^5] 内。
 * -10^9 
 * 所有 Node.val 互不相同 。
 * p != q
 * p 和 q 均存在于给定的二叉树中。
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
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* ans;
    // TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    //     if(!root) {
    //         return nullptr;
    //     }

    //     if(root==p||root==q) {
    //         return root;
    //     }

    //     // left和right都存在时，即找到根，且根会随着left/right返回递归上一级
    //     auto left = lowestCommonAncestor(root->left, p, q);
    //     auto right = lowestCommonAncestor(root->right, p, q);
    //     // 都存在，说明pq在root两侧，最近公共祖先是root
    //     if(left&&right) {
    //         return root;
    //     }
    //     // 只有一个存在，则说明在同一侧，最近公共祖先跟着递归返回
    //     if(left) {
    //         return left;
    //     }
    //     return right;
    // }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        dfs(root, p, q);
        return ans;
    }

    // 两位二进制数字标记：个位1：p，十位1：q
    int dfs(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) {
            return 0;
        }
        int state = dfs(root->left, p, q);
        if(root==p) {
            state |= 1;
        }
        else if(root==q) {
            state |= 2;
        }
        state |= dfs(root->right, p, q);
        if(state==3&&!ans) {
            ans = root;
        }
        return state;
    }
};
// @lc code=end

