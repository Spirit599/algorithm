//BFS

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
    int amountOfTime(TreeNode* root, int start) {
        
        vector<int> edges[100005];
        queue<TreeNode*> que;
        que.push(root);

        while(!que.empty())
        {
            TreeNode* cur = que.front();
            que.pop();

            if(cur->left)
            {
                que.push(cur->left);
                edges[cur->val].push_back(cur->left->val);
                edges[cur->left->val].push_back(cur->val);
            }

            if(cur->right)
            {
                que.push(cur->right);
                edges[cur->val].push_back(cur->right->val);
                edges[cur->right->val].push_back(cur->val);
            }

        }

        bool visited[100005];
        memset(visited, 0, sizeof(visited));
        queue<int> q;
        q.push(start);
        visited[start] = true;
        int ans = -1;

        while(!q.empty())
        {
            int k = q.size();
            ++ans;
            while(k--)
            {
                int cur = q.front();
                q.pop();

                for(int next : edges[cur])
                {
                    if(!visited[next])
                    {
                        visited[next] = true;
                        q.push(next);
                    }
                }
            }
        }

        return ans;
    }
};