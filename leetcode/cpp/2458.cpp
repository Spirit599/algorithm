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
        int height[n];
        memset(height, 0 ,sizeof(height));
        

        function<int(TreeNode*)> dfsForHeight = [&](TreeNode* p) -> int {
            if(p == nullptr)
                return 0;

            int ll = dfsForHeight(p->left);
            int rr = dfsForHeight(p->right);

            return height[p->val] = max(ll, rr) + 1;
        };
        dfsForHeight(root);

        vector<int> ans(n, height[root->val]);

        function<void(TreeNode*, int, int)> dfsForCompute = [&](TreeNode* p, int depth, int longLength) -> void {

            // printf("%d\n", p->val);
            if(p->left && p->right)
            {
                int ll = height[p->left->val];
                int rr = height[p->right->val];
                if(ll > rr)
                {
                    longLength = max(longLength, rr + depth);
                    ans[p->left->val] = longLength;
                    dfsForCompute(p->left, depth + 1, longLength);
                }
                else if(rr > ll)
                {
                    longLength = max(longLength, ll + depth);
                    ans[p->right->val] = longLength;
                    dfsForCompute(p->right, depth + 1, longLength);
                }
            }
            else if(p->left)
            {
                longLength = max(longLength, depth);
                ans[p->left->val] = longLength;
                dfsForCompute(p->left, depth + 1, longLength);
            }
            else if(p->right)
            {
                longLength = max(longLength, depth);
                ans[p->right->val] = longLength;
                dfsForCompute(p->right, depth + 1, longLength);
            }
        };
        dfsForCompute(root, 1, 0);

        int k = queries.size();
        vector<int> ret(k);
        for(int i = 0; i < k; ++i)
        {
            ret[i] = ans[queries[i]] - 1;
        }
        return ret;



    }
};