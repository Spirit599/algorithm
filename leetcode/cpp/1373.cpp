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
    struct status
    {
        bool isBST;
        int sum;
        int maxx;
        int minn;
    };
    int maxSumBST(TreeNode* root) {

        int ans = 0;
        int inf = 0x3f3f3f3f;

        function<status(TreeNode*)> dfs = [&](TreeNode* p) -> status {

            if(!p)
                return {true, 0, -inf, inf};
            
            int sum = p->val;
            int maxx = p->val;
            int minn = p->val;
            status retLeft = dfs(p->left);
            status retRight = dfs(p->right);

            if(retLeft.isBST && retRight.isBST && retLeft.maxx < p->val && retRight.minn > p->val)
            {
                sum += retLeft.sum;
                minn = min(minn, retLeft.minn);
                sum += retRight.sum;
                maxx = max(maxx, retRight.maxx);

                ans = max(ans, sum);
                return {true, sum, maxx, minn};
            }
            else
            {
                return {false, 0, 0, 0};
            }
        };

        dfs(root);
        return ans;
    }
};