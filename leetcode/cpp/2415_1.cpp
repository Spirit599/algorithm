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
    TreeNode* helper(TreeNode* pleft, TreeNode* pright, int depth) 
    {

        if(!pleft)
            return nullptr;
        if(!(depth & 1))
        {
            swap(pleft->val, pright->val);
        }
        helper(pleft->left, pright->right, depth + 1);
        helper(pleft->right, pright->left, depth + 1);

        return root;
    }
    TreeNode* reverseOddLevels(TreeNode* root) {
        
        return helper(root->left, root->right, 0);
    }
};