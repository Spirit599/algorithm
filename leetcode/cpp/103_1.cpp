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
    void dfs(TreeNode *p, int depth)
    {
        if(p)
        {
            if(ans.size() == depth)
                ans.push_back(vector<int>());
            ans[depth].push_back(p->val);
            dfs(p->left, depth + 1);
            dfs(p->right, depth + 1);
        }
    }
    void change()
    {
        bool odd = false;
        int n = ans.size();
        for(int i = 0; i < n; ++i)
        {
            if(odd)
                reverse(ans[i].begin(), ans[i].end());
            odd = !odd;
        }
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {

        dfs(root, 0);
        change();

        return ans;
    }
};