// 236. 二叉树的最近公共祖先

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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        if(!root)
            return nullptr;
        if(root == p || root == q)
            return root;
        TreeNode* retLeft = lowestCommonAncestor(root->left, p, q);
        TreeNode* retRight = lowestCommonAncestor(root->right, p, q);

        if(retLeft && retRight)
            return root;
        else if(retLeft)
            return retLeft;
        else if(retRight)
            return retRight;
        else 
            return nullptr;
    }
};