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

	vector<TreeNode*> dfs(int ll, int rr) {

		if(ll > rr)
			return {nullptr};

		vector<TreeNode*> ret;
		for(int i = ll; i <= rr; ++i)
		{
			auto leftSubTree = dfs(ll, i - 1);
			auto rightSubTree = dfs(i + 1, rr);

			for(auto& lst : leftSubTree)
			{
				for(auto& rst : rightSubTree)
				{
					TreeNode* root = new TreeNode(i);
					root->left = lst;
					root->right = rst;
					ret.emplace_back(root);
				}
			}
		}

		return ret;

	}

    vector<TreeNode*> generateTrees(int n) {

    	
    	return dfs(1, n);

    }
};