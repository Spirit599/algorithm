/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//平衡二叉树
class Solution {
public:
    pair<bool, int> dfs(TreeNode* root)
    {
        if(!root)
            return {true, 0};
        pair<bool, int> lb = dfs(root->left);
        pair<bool, int> rb = dfs(root->right);
        return {lb.first && rb.first && abs(lb.second - rb.second) <= 1,
                max(lb.second, rb.second) + 1};
    }
    bool isBalanced(TreeNode* root) {

        return (dfs(root)).first;
    }
};