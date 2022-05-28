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
    vector<vector<int>> levelOrder(TreeNode* root) {

        vector<vector<int>> ans;
        if(!root)
            return ans;

        queue<TreeNode*> que;
        que.push(root);

        while(!que.empty())
        {
            int len = que.size();
            vector<int> anss;
            for (int i = 0; i < len; ++i)
            {
                TreeNode* cur = que.front();
                que.pop();
                anss.push_back(cur->val);
                if(cur->left)
                    que.push(cur->left);
                if(cur->right)
                    que.push(cur->right);
            }
            ans.push_back(anss);
        }

        return ans;
    }
};