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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        
        for(auto vec : descriptions)
        {
            edges[vec[0]].push_back(make_pair(vec[1], vec[2]));
            son.insert(vec[1]);
        }
        int root_int = 0;
        for(auto vec : descriptions)
        {
            auto it = son.find(vec[0]);
            if(it == son.end())
            {
                root_int = vec[0];
                break;
            }
        }

        cout<<root_int<<endl;

        queue<TreeNode*> que;
        TreeNode* root = new TreeNode(root_int);
        que.push(root);

        while(!que.empty())
        {
            TreeNode* cur = que.front();
            que.pop();
            for(auto pii : edges[cur->val])
            {
                if(pii.second == 1)
                {
                    TreeNode* left = new TreeNode(pii.first);
                    cur->left = left;
                    que.push(left);
                }
                else
                {
                    TreeNode* right = new TreeNode(pii.first);
                    cur->right = right;
                    que.push(right);
                }
            }
        }

        return root;
        
    }
private:
    vector<pair<int, int>> edges[100005];
    unordered_set<int> son;
};