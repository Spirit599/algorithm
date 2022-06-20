//508. 出现次数最多的子树元素和

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
    unordered_map<int, int> memo;
    int max_cnt = 0;

    int dfs(TreeNode* root)
    {
        if(root == nullptr)
            return 0;

        int val = dfs(root->left) + dfs(root->right) + root->val;
        int k = ++memo[val];
        max_cnt = max(max_cnt, k);
        return val;
    }

    vector<int> findFrequentTreeSum(TreeNode* root) {

        dfs(root);

        vector<int> ans;
        for(auto& kav : memo)
            if(kav.second == max_cnt)
                ans.push_back(kav.first);

        return ans;;
    }
};