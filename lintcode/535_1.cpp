//535 · 打劫房屋 III

/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */

class Solution {
public:
    /**
     * @param root: The root of binary tree.
     * @return: The maximum amount of money you can rob tonight
     */
    unordered_map<TreeNode*, int> memo;
    int dfs(TreeNode* p)
    {
        if(p == nullptr)
            return 0;
        if(memo.count(p) == 1)
            return memo[p];

        int val = p->val;
        if(p->left)
            val += dfs(p->left->left) + dfs(p->left->right);
        if(p->right)
            val += dfs(p->right->left) + dfs(p->right->right);

        return memo[p] = max(val, dfs(p->left) + dfs(p->right));
    }

    int houseRobber3(TreeNode *root) {

        return dfs(root);
    }


};