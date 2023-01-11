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
    int sumNumbers(TreeNode* root) {

        int ans = 0;

        function<void(TreeNode*, int)> dfs = [&](TreeNode* p, int cur) {

            if(!p)
                return ;
            cur = 10 * cur + p->val;
            if(p->left == nullptr && p->right == nullptr)
            {
                ans += cur;
            }
            else
            {
                dfs(p->left, cur);
                dfs(p->right, cur);
            }
        };

        dfs(root, 0);
        return ans;
    }
};