/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int maxDepth(TreeNode* root)
    {
        if(!root)
            return 0;
        return max(maxDepth(root->left), maxDepth(root->right)) + 1;

    }
    // int maxDepth(TreeNode* root) {

    //     if(!root)
    //         return 0;

    //     int ans = 0;
    //     queue<TreeNode*> que;
    //     que.push(root);

    //     while(!que.empty())
    //     {
    //         int len = que.size();
    //         while(len--)
    //         {
    //             TreeNode* cur = que.front();
    //             que.pop();
    //             if(cur->left)
    //                 que.push(cur->left);
    //             if(cur->right)
    //                 que.push(cur->right);
    //         }
    //         ++ans;
    //     }
    //     return ans;
    // }
};