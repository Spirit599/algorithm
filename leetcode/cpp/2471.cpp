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
    int minimumOperations(TreeNode* root) {
        
        int ans = 0;
        if(!root)
            return ans;
        queue<TreeNode*> que;
        que.push(root);

        while(!que.empty())
        {
            vector<int> tmp;
            int k = que.size();
            while(k--)
            {
                TreeNode* cur = que.front();
                tmp.push_back(cur->val);
                que.pop();
                if(cur->left)
                    que.push(cur->left);
                if(cur->right)
                    que.push(cur->right);
            }
            int ret = computerArray(tmp);
            // printf("%d\n", ret);
            ans += ret;
        }

        return ans;
    }

    int computerArray(vector<int>& arr)
    {
        vector<int> arr1(arr);
        sort(arr1.begin(), arr1.end());
        unordered_map<int, int> memo;

        int n = arr.size();
        for(int i = 0; i < n; ++i)
        {
            memo[arr[i]] = i;
        }

        int ret = 0;
        for(int i = 0; i < n; ++i)
        {
            if(arr1[i] != arr[i])
            {
                ++ret;
                memo[arr[i]] = memo[arr1[i]];
                swap(arr[i], arr[memo[arr1[i]]]);
            }
        }
        return ret;
    }
};