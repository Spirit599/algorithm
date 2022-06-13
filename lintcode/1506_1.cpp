/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */

class Solution {
public:
    /**
     * @param root: the root of the tree
     * @param target: the target
     * @param k: the given K
     * @return: All Nodes Distance K in Binary Tree
     *          we will sort your return value in output
     */
    vector<int> distanceK(TreeNode *root, TreeNode *target, int k) {

        if(k == 0)
            return {target->val};
        
        unordered_map<int, vector<int>> edges;

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

        vector<int> ans;
        unordered_set<int> visited;
        queue<int> q;
        q.push(target->val);
        visited.insert(target->val);

        while(!q.empty())
        {
            --k;
            int q_num = q.size();

            while(q_num--)
            {
                int cur = q.front();
                q.pop();

                for(int edge : edges[cur])
                {
                    if(visited.count(edge) == 0)
                    {
                        q.push(edge);
                        visited.insert(edge);
                        if(k == 0)
                            ans.push_back(edge);
                    }
                }
            }

            if(k == 0)
                break;
        }

        return ans;
    }
};