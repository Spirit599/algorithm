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
    TreeNode* insertIntoBST(TreeNode* root, int val) {

    	TreeNode* p = root;
    	if(!p)
    		return new TreeNode(val);
    	while(1)
    	{
    		if(p->val > val)
    		{
    			if(!p->left)
    			{
    				p->left = new TreeNode(val);
    				return root;
    			}
    			else
    			{
    				p = p->left;
    			}
    		}
    		else
    		{
    			if(!p->right)
    			{
    				p->right = new TreeNode(val);
    				return root;
    			}
    			else
    			{
    				p = p->right;
    			}
    		}
    	}

    	return nullptr;
    }
};