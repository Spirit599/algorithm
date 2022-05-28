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
    TreeNode* ans = NULL;
public:
    pair<bool, bool> dfs(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        if(!root)
            return {false, false};
        pair<bool, bool> p1 = dfs(root->left, p, q);
        pair<bool, bool> p2 = dfs(root->right, p, q);

        if(ans)
            return {true, true};

        bool b1 = {p1.first || p2.first || root == p};
        bool b2 = {p1.second || p2.second || root == q};

        if(b1 && b2)
        {
            cout<<root->val<<endl;
            ans = root;
            return {b1, b2};
        }

        return {b1, b2};

    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        if(!root)
            return NULL;
        dfs(root, p, q);

        return ans;
    }
};