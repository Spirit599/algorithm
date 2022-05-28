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
    vector<vector<int>> ans;
public:
    void dfs(TreeNode* root, int target, vector<int>& path)
    {
        if(!root)
            return ;
        
        if(!root->left && !root->right && target == root->val)
        {
            path.push_back(root->val);
            ans.push_back(path);
            path.pop_back();
            return ;
        }

        path.push_back(root->val);
        dfs(root->left, target - root->val, path);
        dfs(root->right, target - root->val, path);
        path.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int target) {

        vector<int> path;
        dfs(root, target, path);

        return ans;
    }
};