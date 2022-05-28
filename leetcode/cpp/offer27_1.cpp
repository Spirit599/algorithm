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
    void swap_subtree(TreeNode* root)
    {
        if(root)
        {
            swap(root->left, root->right);
            swap_subtree(root->left);
            swap_subtree(root->right);
        }
    }

    TreeNode* mirrorTree(TreeNode* root) {

        if(!root)
            return NULL;

        swap_subtree(root);

        return root;
    }
};