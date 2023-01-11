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
    int ans = 0;
    pair<int, int> dfs(TreeNode* p) {

        if(p == nullptr)
            return make_pair(0, 0);
        pair<int, int> ret;
        auto leftRet = dfs(p->left);
        auto rightRet = dfs(p->right);
        ret.first = leftRet.first + rightRet.first + 1;
        ret.second = leftRet.second + rightRet.second + p->val;
        if(p->val == ret.second / ret.first)
            ++ans;
        return ret;
    }
    int averageOfSubtree(TreeNode* root) {
        
        dfs(root);
        return ans;
    }
};