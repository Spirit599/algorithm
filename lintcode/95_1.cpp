// 95 · 验证二叉查找树

/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */

class Solution {
public:
    /**
     * @param root: The root of binary tree.
     * @return: True if the binary tree is BST, or false
     */
    struct ret
    {
        int max;
        int min;
        bool isBST;
    };

    ret dfs(TreeNode *p)
    {
        if(p->left == nullptr && p->right == nullptr)
        {
            return {p->val, p->val, true};
        }
        else if(p->left && p->right)
        {
            ret left_ret = dfs(p->left);
            ret right_ret = dfs(p->right);
            return {right_ret.max, left_ret.min,
                    left_ret.isBST && right_ret.isBST && left_ret.max < p->val && p->val < right_ret.min};
        }
        else if(p->left)
        {
            ret left_ret = dfs(p->left);
            return {p->val, left_ret.min,
                    left_ret.isBST && left_ret.max < p->val};
        }
        else if(p->right)
        {

            ret right_ret = dfs(p->right);
            return {right_ret.max, p->val,
                    right_ret.isBST && p->val < right_ret.min};
        }

    }

    bool isValidBST(TreeNode *root) {

        if(root)
            return dfs(root).isBST;
        else
            return true;
    }
};