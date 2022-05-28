/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> levelOrder(TreeNode* root) {

        vector<int> ans;
        if(!root)
            return ans;

        queue<TreeNode*> que;
        que.push(root);

        
        while(!que.empty())
        {
            TreeNode* cur = que.front();
            que.pop();
            ans.push_back(cur->val);
            if(cur->left)
                que.push(cur->left);
            if(cur->right)
                que.push(cur->right);
        }

        return ans;
    }
};