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
private:
    bool ans = true;
public:
    void dfs(TreeNode* p1, TreeNode* p2)
    {
        if(!ans)
            return;
        if(!p1 && !p2)
            return;
        if(!p1 || !p2)
        {
            ans = false;
            return;
        }
        if(p1->val != p2->val)
        {
            ans = false;
            return;
        }
        dfs(p1->left, p2->right);
        dfs(p1->right, p2->left);
    }
    bool isSymmetric(TreeNode* root) {

        if(!root)
            return true;

        dfs(root->left, root->right);
        return ans;
    }
};