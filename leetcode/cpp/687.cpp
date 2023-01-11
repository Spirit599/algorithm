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
    int longestUnivaluePath(TreeNode* root) {

        if(!root)
            return 0;

        int ans = 0;
        function<int(TreeNode*)> dfs = [&](TreeNode* p) -> int {

            int ret = 1;
            int left = 0;
            int right = 0;
            if(p->left)
            {
                int ll = dfs(p->left);
                if(p->left->val == p->val)
                    left = ll;
            }
            if(p->right)
            {
                int rr = dfs(p->right);
                if(p->right->val == p->val)
                    right = rr;
            }

            ans = max(ans, ret + left + right);
            return ret + max(left, right);
        };

        dfs(root);
        return ans - 1;
    }
};