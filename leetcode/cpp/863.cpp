/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        
        vector<int> ans;
        unordered_map<TreeNode*, vector<TreeNode*>> edges;

        function<void(TreeNode*)> dfs = [&](TreeNode* p) -> void {

        	if(p->left)
        	{
        		edges[p].push_back(p->left);
        		edges[p->left].push_back(p);
        		dfs(p->left);
        	}
        	if(p->right)
        	{
        		edges[p].push_back(p->right);
        		edges[p->right].push_back(p);
        		dfs(p->right);
        	}
        };
        dfs(root);

        function<void(TreeNode* ,TreeNode*, int)> dfs1 = [&](TreeNode* fa, TreeNode* p, int cur) -> void {

        	if(cur == k)
        	{
        		ans.push_back(p->val);
        		return ;
        	}

        	for(auto pnext : edges[p])
        	{
        		if(pnext != fa)
        		{
        			dfs1(p, pnext, cur + 1);
        		}
        	}
        };

        dfs1(nullptr, target, 0);
        return ans;
    }
};