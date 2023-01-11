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
    vector<int> rightSideView(TreeNode* root) {

        vector<int> ans;

        function<void(TreeNode*, int)> dfs = [&](TreeNode* p, int depth) {

            if(!p)
                return;
            if(ans.size() == depth)
                ans.resize(depth + 1);
            ans[depth] = p->val;
            dfs(p->left, depth + 1);
            dfs(p->right, depth + 1);
        };
        dfs(root, 0);
        return ans;
    }
};