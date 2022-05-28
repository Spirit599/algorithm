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
     * @param root: the root of the binary tree
     * @return: An integer
     */
    int ans = 0;
    void dfs(TreeNode *root)
    {
        if(root == NULL)
            return ;

        if(root->left == NULL && root->right == NULL)
        {
            ans += root->val;
        }
        else
        {
            dfs(root->left);
            dfs(root->right);
        }
    }
    int leafSum(TreeNode *root) {
        
        dfs(root);

        return ans;
    }
};