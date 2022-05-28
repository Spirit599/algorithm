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
     * @return: An integer
     */
    int maxDepth(TreeNode *root) {

        if(root == NULL)
            return 0;
        
        int level = 0;
        queue<TreeNode*> que;
        que.emplace(root);

        while(!que.empty())
        {
            int n = que.size();
            ++level;
            while(n--)
            {
                TreeNode* cur = que.front();
                que.pop();
                if(cur->left)
                    que.emplace(cur->left);
                if(cur->right)
                    que.emplace(cur->right);
            }
        }

        return level;
    }
};