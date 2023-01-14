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
	int ans = INT_MIN;
	int dfs(TreeNode* p) {

		if(!p)
    		return 0;
    	int val = p->val;
    	int leftVal = max(dfs(p->left), 0);
    	int rightVal = max(dfs(p->right), 0);
    	ans = max(ans, val + leftVal + rightVal);
    	// printf("%d %d %d\n", val, leftVal, rightVal);
    	return val + max(leftVal, rightVal);
	}
    int maxPathSum(TreeNode* p) {

    	dfs(p);
    	return ans;
    }
};