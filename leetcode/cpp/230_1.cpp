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
    int kthSmallest(TreeNode* root, int k) {

        stack<TreeNode*> sta;
        TreeNode* p = root;
        while(!sta.empty() || p)
        {
            if(p)
            {
                
                sta.push(p);
                p = p->left;

            }
            else
            {
                TreeNode* cur = sta.top();

                if(--k == 0)
                    return cur->val;
                sta.pop();
                p = cur->right;
            }
        }

        return 0;
    }
};