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
    int findBottomLeftValue(TreeNode* root) {

        int ans = 0;
        int maxDepth = -1;

        function<void(TreeNode*, int)> dfs = [&](TreeNode* p, int depth) {
            
            if(p == nullptr)
                return ;
            if(maxDepth < depth)
            {
                maxDepth = depth;
                ans = p->val;
            }
            dfs(p->left, depth + 1);
            dfs(p->right, depth + 1);
        };

        dfs(root, 0);
        return ans;

    }
};