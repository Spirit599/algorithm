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
     * @return: True if this Binary tree is Balanced, or false.
     */
    pair<bool, int> is_balanced(TreeNode* p)
    {
        if(p == NULL)
            return {true, 0};

        pair<bool, int> left_ret = is_balanced(p->left);
        pair<bool, int> right_ret = is_balanced(p->right);

        return {left_ret.first && right_ret.first && abs(left_ret.second - right_ret.second) <= 1,
                max(left_ret.second, right_ret.second) + 1};
    }

    bool isBalanced(TreeNode *root) {
        
        return is_balanced(root).first;
    }
};