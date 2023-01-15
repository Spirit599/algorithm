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
    int deepestLeavesSum(TreeNode* root) {


    	queue<TreeNode*> que;
    	que.push(root);
    	int ans = 0;

    	while(!que.empty())
    	{
    		int k = que.size();
    		ans = 0;
    		while(k--)
    		{
    			TreeNode* cur = que.front();
    			que.pop();
    			ans += cur->val;
    			if(cur->left)
    				que.push(cur->left);
    			if(cur->right)
    				que.push(cur->right);
    		}
    	}
    	return ans;
    }
};