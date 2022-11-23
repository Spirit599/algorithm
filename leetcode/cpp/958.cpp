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
    bool isCompleteTree(TreeNode* root) {


        queue<TreeNode*> que;
        que.emplace(root);
        bool last = false;

        while(!que.empty())
        {
            TreeNode* cur = que.front();
            que.pop();

            if(cur == nullptr)
            {
                last = true;
                continue;
            }
            else
            {
                if(last)
                    return false;
            }

            que.emplace(cur->left);
            que.emplace(cur->right);
        }

        return true;
    }
};