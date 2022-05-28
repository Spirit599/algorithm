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
     * @param root: The root of binary tree
     * @return: An integer
     */
    int minDepth(TreeNode *root) {

        if(root == NULL)
            return 0;
        
        queue<TreeNode*> que;
        que.emplace(root);
        int level = 0;

        while(!que.empty())
        {
            int n = que.size();
            ++level;
            cout<<level<<endl;
            while(n--)
            {
                TreeNode* cur = que.front();
                que.pop();

                if(cur->left == NULL && cur->right == NULL)
                    return level;
                else
                {
                    if(cur->left)
                        que.emplace(cur->left);
                    if(cur->right)
                        que.emplace(cur->right);
                }
            }
        }

        return -1;
    }
};