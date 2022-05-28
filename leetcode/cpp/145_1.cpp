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
    vector<int> ret;
public:
    vector<int> postorderTraversal(TreeNode* root) {

        if(root)
        {
            postorderTraversal(root->left);
            postorderTraversal(root->right);
            ret.push_back(root->val);
        }

        return ret;
    }
};