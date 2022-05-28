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
     * @param root: the root of the binary tree
     * @param level: the depth of the target level
     * @return: An integer
     */
    int levelSum(TreeNode *root, int level) {
        
        queue<TreeNode*> que;

        if(root)
            que.emplace(root);

        while(!que.empty())
        {
            int n = que.size();
            int sum = 0;
            while(n--)
            {
                TreeNode* cur = que.front();
                que.pop();
                sum += cur->val;
                if(cur->left)
                    que.emplace(cur->left);
                if(cur->right)
                    que.emplace(cur->right);
            }

            --level;
            if(level == 0)
                return sum;
            
            
        }

        return 0;
    }
};