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
        
        if(root == nullptr)
            return nullptr;
        if(p == root || q == root)
            return root;
        TreeNode* ll = lowestCommonAncestor(root->left, p, q);
        TreeNode* rr = lowestCommonAncestor(root->right, p, q);
        if(ll && rr)
            return root;
        else if(ll)
            return ll;
        else if(rr)
            return rr;
        else
            return nullptr;
    }
};