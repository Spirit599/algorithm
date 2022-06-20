//94 · 二叉树中的最大路径和

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
     * @return: An integer
     */
    int ans = -0x7fffffff;
    int singlePathSum(TreeNode* root)
    {
        if(root == nullptr)
            return 0;
        
        int left = max(singlePathSum(root->left), 0);
        int right = max(singlePathSum(root->right), 0);
        ans = max(ans, left + right + root->val);
        return max(left, right) + root->val;
    }
    int maxPathSum(TreeNode *root) {
        
        singlePathSum(root);
        return ans;
    }
};