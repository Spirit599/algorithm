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
    int ans = INT_MIN;
    int singlePathSum(TreeNode* p)
    {
        if(!p)
            return 0;
        int leftSum = singlePathSum(p->left);
        int rightSum = singlePathSum(p->right);
        ans = max(ans, p->val + max(leftSum, 0) + max(rightSum, 0));
        return p->val + max({leftSum, rightSum, 0});

    }
    int maxPathSum(TreeNode* root) {

        singlePathSum(root);
        return ans;
    }
};