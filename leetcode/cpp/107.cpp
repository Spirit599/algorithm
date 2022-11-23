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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {

        vector<vector<int>> ans;
        if(!root)
            return ans;

        queue<TreeNode*> que;
        que.push(root);

        while(!que.empty())
        {
            int k = que.size();
            vector<int> anss;
            while(k--)
            {
                TreeNode* cur = que.front();
                que.pop();
                anss.push_back(cur->val);
                if(cur->left)
                    que.push(cur->left);
                if(cur->right)
                    que.push(cur->right);
            }
            ans.emplace_back(std::move(anss));
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};