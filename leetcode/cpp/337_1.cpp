// 337. 打家劫舍 III

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
	unordered_map<TreeNode*, int> memo;
    int rob(TreeNode* root) {

    	if(!root)
    		return 0;

    	auto it = memo.find(root);
    	if(it != memo.end())
    		return it->second;

    	int val = root->val;
    	if(root->left)
    		val += rob(root->left->left) + rob(root->left->right);
    	if(root->right)
    		val += rob(root->right->left) + rob(root->right->right);

    	return memo[root] = max(val, rob(root->left) + rob(root->right));

    }
};