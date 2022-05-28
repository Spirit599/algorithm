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
     * @param root: the root of binary tree
     * @param target: An integer
     * @return: all valid paths
     *          we will sort your return value in output
     */
    vector<vector<int>> ans;

    void dfs(vector<int>& cur, int target, TreeNode* p)
    {
        cout<<p->val<<endl;
        if(p->left == NULL && p->right == NULL)
        {
            if(target == 0)
            {
                //cur.emplace_back(target);
                ans.emplace_back(cur);
                //cur.pop();
            }
            return ;
        }
        if(p->left)
        {
            cur.emplace_back(p->left->val);
            dfs(cur, target - p->left->val, p->left);
            cur.pop_back();
        }
        if(p->right)
        {
            cur.emplace_back(p->right->val);
            dfs(cur, target - p->right->val, p->right);
            cur.pop_back();
        }
    }

    vector<vector<int>> binaryTreePathSum(TreeNode *root, int target) {
        
        if(root)
        {
            vector<int> cur;
            cur.emplace_back(root->val);
            dfs(cur, target - root->val, root);
        }

        return ans;
    }
};