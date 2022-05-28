/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */


//中序遍历
class Solution {
private:
    int ans = 0;
    int i = 0;
public:
    void dfs(TreeNode* root, int k)
    {
        if(!root || i > k)
            return ;

        dfs(root->right, k);
        ++i;
        //cout<<i<<" "<<root->val<<endl;
        if(i == k)
        {
            ans = root->val;
            return ;
        }
        dfs(root->left, k);
    }
    int kthLargest(TreeNode* root, int k) {

        dfs(root, k);
        //cout<<ans<<endl;
        return ans;
    }
};