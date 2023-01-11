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
    
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        
        int n = queries.size();
        vector<vector<int>> ans(n);

        vector<int> arr;
        function<void(TreeNode*)> dfs = [&](TreeNode* p)
        {
            if(p == nullptr)
                return ;
            dfs(p->left);
            arr.push_back(p->val);
            dfs(p->right);
        };

        dfs(root);

        for(int i = 0; i < n; ++i)
        {
            auto it1 = lower_bound(arr.begin(), arr.end(), queries[i]);
            auto it2 = upper_bound(arr.begin(), arr.end(), queries[i]);

            int ret1 = -1;
            if(it1 != arr.end())
                ret1 = *it1;

            int ret2 = -1;
            if(it2 != arr.begin())
            {

                ret2 = *(--it2);
            }

            ans[i] = {ret2, ret1}; 
        }

        return ans;

    }
};