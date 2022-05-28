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
    int ans = 0;
public:
    void dfs(TreeNode* root, vector<int>& path)
    {
        if(root->left == NULL && root->right == NULL)
        {
            int num = root->val;
            int path_size = path.size();
            for (int i = 0; i < path_size; ++i)
            {
                num += pow(2, (path_size - i)) * path[i];
            }
            ans += num;
        }
        else
        {
            path.push_back(root->val);
            if(root->left)
            {
                dfs(root->left, path);
            }
            if(root->right)
            {
                dfs(root->right, path);
            }
            path.pop_back();
        }
    }
    int sumRootToLeaf(TreeNode* root) {

        vector<int> path;
        dfs(root, path);

        return ans;
    }
};