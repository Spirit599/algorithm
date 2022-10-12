// 剑指 Offer II 051. 节点之和最大的路径
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
    int maxPathSum(TreeNode* root) {
    	maxSinglePathSum(root);
    	return ans;
    }
    int maxSinglePathSum(TreeNode* p) {
    	if(!p)
    		return 0;
    	int leftSum = max(maxSinglePathSum(p->left), 0);
    	int rightSum = max(maxSinglePathSum(p->right), 0);
    	ans = max(ans, p->val + leftSum + rightSum);
    	return p->val + max(leftSum, rightSum);
    }
};