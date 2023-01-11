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
    vector<int> largestValues(TreeNode* root) {

        vector<int> ans;
        

        function<void(TreeNode*, int)> dfs = [&](TreeNode* p, int depth) {
            
            if(p == nullptr)
                return ;
            if(ans.size() == depth)
                ans.push_back(p->val);
            ans[depth] = max(ans[depth], p->val);
            dfs(p->left, depth + 1);
            dfs(p->right, depth + 1);
        };

        dfs(root, 0);

        return ans;
    }
};