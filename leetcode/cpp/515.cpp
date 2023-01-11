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
    vector<int> largestValues(TreeNode* root) {

        vector<int> ans;
        if(root == nullptr)
            return ans;

        queue<TreeNode*> que;
        que.push(root);

        while(!que.empty())
        {
            int k = que.size();
            int maxx = (que.front()->val);
            while(k--)
            {
                TreeNode* cur =  que.front();
                que.pop();
                maxx = max(maxx, cur->val);
                if(cur->left)
                    que.push(cur->left);
                if(cur->right)
                    que.push(cur->right);
            }
            ans.push_back(maxx);
        }

        return ans;
    }
};