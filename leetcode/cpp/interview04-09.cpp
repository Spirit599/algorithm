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
    vector<vector<int>> BSTSequences(TreeNode* root) {

        auto ret = helper(root);
        for(auto& vec : ret)
            reverse(vec.begin(), vec.end());
        return ret;
    }
    vector<vector<int>> helper(TreeNode* p) {

        
        if(!p)
            return vector<vector<int>>({vector<int>()});

        vector<vector<int>> ret;
        auto leftRet = helper(p->left);
        auto rightRet = helper(p->right);
        vector<int> cur;
        int leftSize = leftRet.size();
        int rightSize = rightRet.size();
        int m,n;

        function<void(vector<int>&, vector<int>&, vector<int>&, int, int)> dfs = [&](vector<int>& cur, vector<int>& v1, vector<int>& v2, int idx1, int idx2) {

            if(idx1 == m && idx2 == n)
            {
                ret.emplace_back(cur);
            }
            else if(idx1 != m && idx2 != n)
            {
                cur.emplace_back(v1[idx1]);
                dfs(cur, v1, v2, idx1 + 1, idx2);
                cur.pop_back();
                cur.emplace_back(v2[idx2]);
                dfs(cur, v1, v2, idx1, idx2 + 1);
                cur.pop_back();
            }
            else if(idx1 != m)
            {
                cur.emplace_back(v1[idx1]);
                dfs(cur, v1, v2, idx1 + 1, idx2);
                cur.pop_back();
            }
            else if(idx2 != n)
            {
                cur.emplace_back(v2[idx2]);
                dfs(cur, v1, v2, idx1, idx2 + 1);
                cur.pop_back();
            }
        };

        for(int i = 0; i < leftSize; ++i)
        {
            for(int j = 0; j < rightSize; ++j)
            {
                cur.clear();
                m = leftRet[i].size();
                n = rightRet[j].size();
                dfs(cur, leftRet[i], rightRet[j], 0, 0);
            }
        }

        for(auto& vec : ret)
            vec.emplace_back(p->val);
        
        return ret;

    }
};