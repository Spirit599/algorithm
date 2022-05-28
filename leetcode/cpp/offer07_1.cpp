/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//中序 前序 还原二叉树
class Solution {
private:
    unordered_map<int, int> memo;
    TreeNode* rebuild(vector<int>& preorder, vector<int>& inorder,
                        int pre_left, int pre_right,
                        int in_left, int in_right)
    {
        if(pre_left > pre_right)
            return NULL;
        int pre_root = pre_left;
        int in_root = memo[preorder[pre_root]];

        TreeNode* root = new TreeNode(preorder[pre_root]);
        int left_subtree_num = in_root - in_left;

        root->left = rebuild(preorder, inorder,
                            pre_left + 1, pre_left + left_subtree_num,
                            in_left, in_root - 1);

        root->right = rebuild(preorder, inorder,
                            pre_left + left_subtree_num + 1, pre_right,
                            in_root + 1, in_right);

        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

        int n = inorder.size();
        for (int i = 0; i < n; ++i)
        {
            memo[inorder[i]] = i;
        }

        return rebuild(preorder, inorder,
                        0, n - 1, 0, n - 1);
    }
};