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
    vector<vector<int>> ans;

    void dfs(TreeNode* p, int level)
    {
        if(!p)
            return ;
        if(ans.size() == level)
            ans.push_back(vector<int>());

        ans[level].push_back(p->val);
        dfs(p->left, level + 1);
        dfs(p->right, level + 1);


    }

    vector<vector<int>> levelOrder(TreeNode* root) {

        dfs(root, 0);

        return ans;

    }
};