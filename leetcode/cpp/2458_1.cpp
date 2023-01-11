// dfs序

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
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        
        int n = 100005;
        int ll[n];
        int rr[n];
        memset(ll, 0, sizeof(ll));
        memset(rr, 0, sizeof(rr));

        int index = 0;
        vector<int> dep({0});
        function<void(TreeNode*, int)> dfs = [&](TreeNode* p, int depth) {

            if(p == nullptr)
                return ;

            dep.push_back(depth);
            ll[p->val] = ++index;
            dfs(p->left, depth + 1);
            dfs(p->right, depth + 1);
            rr[p->val] = index;
        };
        dfs(root, 0);
        dep.push_back(0);


        int depSize = dep.size();
        int leftPre[depSize];
        leftPre[0] = 0;
        int rightPre[depSize];
        rightPre[depSize - 1] = 0;
        for(int i = 1; i < depSize; ++i)
            leftPre[i] = max(leftPre[i - 1], dep[i]);
        for(int i = depSize - 2; i >= 0; --i)
            rightPre[i] = max(rightPre[i + 1], dep[i]);

        int k = queries.size();
        vector<int> ret(k);
        for(int i = 0; i < k; ++i)
        {
            int val = queries[i];
            ret[i] = max(leftPre[ll[val] - 1], rightPre[rr[val] + 1]);
        }
        return ret;



    }
};