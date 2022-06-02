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
//450. 删除二叉搜索树中的节点
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {

        if(root == nullptr)
            return nullptr;

        TreeNode* father = nullptr;
        TreeNode* cur = root;
        int left = 0;

        while(cur && cur->val != key)
        {
            father = cur;
            if(cur->val < key)
            {
                cur = cur->right;
                left = 0;
            }
            else if(cur->val > key)
            {
                cur = cur->left;
                left = 1;
            }
        }

        if(cur)
        {
            TreeNode* s = nullptr;
            TreeNode* pre = nullptr;
            if(cur->left)
            {
                s = cur->left;
                pre = nullptr;
                while(s->right)
                {
                    pre = s;
                    s = s->right;
                }

                if(s != cur->left)
                {
                    pre->right = s->left;
                    s->left = cur->left;
                    s->right = cur->right;
                }
                else
                {
                    s->right = cur->right;
                }
            }

            else if(cur->right)
            {
                s = cur->right;
                pre = nullptr;
                while(s->left)
                {
                    pre = s;
                    s = s->left;
                }

                if(s != cur->right)
                {
                    pre->left = s->right;
                    s->left = cur->left;
                    s->right = cur->right;
                }
                else
                {
                    s->left = cur->left;
                }     
            }

            if(cur == root)
                root = s;
            if(father)
            {
                if(left)
                    father->left = s;
                else
                    father->right = s;
            }
        }

        return root;
    }
};