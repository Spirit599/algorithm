// 98. 验证二叉搜索树

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
	struct ret
	{
		int max;
		int min;
		bool isBst;
	};
	ret checkBST(TreeNode* p) {

		if(p->left && p->right)
		{
			ret retLeft = checkBST(p->left);
			ret retRight = checkBST(p->right);
			bool isBst = retRight.min > p->val && retLeft.max < p->val;
			return {retRight.max, retLeft.min, isBst && retRight.isBst && retLeft.isBst};
		}
		else if(p->left)
		{
			ret retLeft = checkBST(p->left);
			bool isBst = retLeft.max < p->val;
			return {p->val, retLeft.min, isBst && retLeft.isBst};
		}
		else if(p->right)
		{
			ret retRight = checkBST(p->right);
			bool isBst = retRight.min > p->val;
			return {retRight.max, p->val, isBst && retRight.isBst};
		}
		else
		{
			bool isBst = true;
			return {p->val, p->val, isBst};
		}
	}
    bool isValidBST(TreeNode* root) {

    	return checkBST(root).isBst;
    }
};