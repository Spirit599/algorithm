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
    TreeNode* dfs(TreeNode* root, int minn, int maxx)
    {
        int cur = root->val;
        if(cur >= minn && cur <= maxx)
            return root;
        else if(cur >= minn)
            return dfs(root->left, minn, maxx);
        else
            return dfs(root->right, minn, maxx);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        

        if(!root)
            return NULL;
        
        int minn = min(p->val, q->val);
        int maxx = max(p->val, q->val);

        return dfs(root, minn, maxx);
    }
};