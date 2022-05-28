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
    vector<vector<int>> ans;
public:
    void dfs(TreeNode* root, int targetSum, vector<int>& path)
    {
        //cout<<targetSum<<" "<<root->val<<endl;
        if(root->left == NULL && root->right == NULL)
        {
            if(targetSum == root->val)
            {
                path.push_back(root->val);
                ans.push_back(path);
                path.pop_back();
            }
            return ;
        }

        if(root->left)
        {
            path.push_back(root->val);
            dfs(root->left, targetSum - root->val, path);
            path.pop_back();
        }

        if(root->right)
        {
            path.push_back(root->val);
            dfs(root->right, targetSum - root->val, path);
            path.pop_back();
        }


    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {

        if(root)
        {
            vector<int> path;
            dfs(root, targetSum, path);
        }

        return ans;
    }
};