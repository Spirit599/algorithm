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

//层序遍历
//记录层数
class Solution {
public:
    int minDepth(TreeNode* root) {

        if(!root)
            return 0;

        int ans = 0;
        queue<TreeNode*> que;
        que.push(root);

        while(!que.empty())
        {
            int len = que.size();
            bool over = false;
            while(len--)
            {
                TreeNode* cur = que.front();
                cout<<cur->val<<endl;
                que.pop();
                if(!cur->left && !cur->right)
                {
                    over = true;
                    break;
                }
                if(cur->left)
                {
                    que.push(cur->left);
                }
                if(cur->right)
                {
                    que.push(cur->right);
                }
            }
            ++ans;
            if(over)
                break;
        }

        return ans;
    }
};