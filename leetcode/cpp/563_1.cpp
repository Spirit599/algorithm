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
private:
    int ans = 0;
public:
    int dfs(TreeNode* root)
    {
        //cout<<root->val<<endl;
        int left_sum = 0;
        int right_sum = 0;
        if(root->left)
            left_sum = dfs(root->left);
        if(root->right)
            right_sum = dfs(root->right);
        ans += abs(left_sum - right_sum);
        return left_sum + right_sum + root->val;

    }
    int findTilt(TreeNode* root) {
        if(!root)
            return 0;
        dfs(root);
        return ans;
    }
};