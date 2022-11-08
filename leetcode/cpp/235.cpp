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
        
        int minn = min(p->val, q->val);
        int maxx = max(p->val, q->val);
        return lowestCommonAncestorHelper(root, minn, maxx);
    }
    TreeNode* lowestCommonAncestorHelper(TreeNode* p, int minn, int maxx)
    {
        int cur = p->val;
        if(minn <= cur && cur <= maxx)
            return p;
        else if(cur > maxx)
            return lowestCommonAncestorHelper(p->left, minn, maxx);
        else if(cur < minn)
            return lowestCommonAncestorHelper(p->right, minn, maxx);
        else
            return nullptr;
    }
};