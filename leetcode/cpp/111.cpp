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
const int MAX_NODE = 100005;
class Solution {
public:
    string getDirections(TreeNode* root, int startValue, int destValue) {
        
        int father[MAX_NODE];
        memset(father, 0, sizeof(father));
        int left_son[MAX_NODE];
        memset(left_son, 0, sizeof(left_son));
        int right_son[MAX_NODE];
        memset(right_son, 0, sizeof(right_son));

        queue<TreeNode*> que;
        que.push(root);
        while(!que.empty())
        {
            auto cur = que.front();
            que.pop();
            //cout<<cur->val<<endl;
            if(cur->left)
            {
                father[cur->left->val] = cur->val;
                left_son[cur->val] = cur->left->val;
                que.push(cur->left);
            }
            if(cur->right)
            {
                father[cur->right->val] = cur->val;
                right_son[cur->val] = cur->right->val;
                que.push(cur->right);
            }
        }

        //string ans[MAX_NODE];
        int next[MAX_NODE];
        memset(next, 0, sizeof(next));
        bool visit[MAX_NODE];
        memset(visit, 0, sizeof(visit));
        visit[startValue] = true;
        queue<int> q;
        q.push(startValue);

        while(!q.empty())
        {

            int cur = q.front();
            //cout<<cur<<" "<<left_son[cur]<<" "<<right_son[cur]<<" "<<father[cur]<<" "<<ans[cur]<<endl;
            q.pop();
            //string cur_str = ans[cur];

            if(cur == destValue)
                break;

            if(left_son[cur] != 0 && !visit[left_son[cur]])
            {
                visit[left_son[cur]] = true;
                //ans[left_son[cur]] = cur_str + 'L';
                next[left_son[cur]] = cur;
                q.push(left_son[cur]);
            }
            if(right_son[cur] != 0 && !visit[right_son[cur]])
            {
                visit[right_son[cur]] = true;
                //ans[right_son[cur]] = cur_str + 'R';
                next[right_son[cur]] = cur;
                q.push(right_son[cur]);
            }
            if(father[cur] != 0 && !visit[father[cur]])
            {
                visit[father[cur]] = true;
                //ans[father[cur]] = cur_str + 'U';
                next[father[cur]] = cur;
                q.push(father[cur]);
            }

        }


        string ans;
        int k = destValue;
        while(k != startValue)
        {

            if(left_son[next[k]] == k)
            {
                ans.push_back('L');
            }
            if(right_son[next[k]] == k)
            {
                ans.push_back('R');
            }
            if(father[next[k]] == k)
            {
                ans.push_back('U');
            }
            k = next[k];
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};