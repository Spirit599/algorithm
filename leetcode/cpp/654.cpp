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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {



    	function<TreeNode*(int, int)> dfs = [&](int left, int right) -> TreeNode* {

    		if(left > right)
    			return nullptr;

    		int idx =  -1;
    		int maxx = -1;
    		for(int i = left; i <= right; ++i)
    		{
    			if(maxx < nums[i])
    			{
    				maxx = nums[i];
    				idx = i;
    			}
    		}

    		TreeNode* p = new TreeNode(maxx);
    		p->left = dfs(left, idx - 1);
    		p->right = dfs(idx + 1, right);
    		return p;
    	};

    	return dfs(0, nums.size() - 1);

    }
};