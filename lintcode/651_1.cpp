// 651 · 二叉树垂直遍历

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
     * @param root: the root of tree
     * @return: the vertical order traversal
     */
    vector<vector<int>> verticalOrder(TreeNode *root) {
        
        if(root == nullptr)
            return vector<vector<int>>();

        
        int left = 0;
        int right = 0;
        queue<pair<TreeNode*, int>> que1;
        que1.push(make_pair(root, 0));

        while(!que1.empty())
        {
            pair<TreeNode*, int> cur = que1.front();
            que1.pop();
            left = min(left, cur.second);
            right = max(right, cur.second);
            
            if(cur.first->left)
                que1.push(make_pair(cur.first->left, cur.second - 1));
            if(cur.first->right)
                que1.push(make_pair(cur.first->right, cur.second + 1));

        }
        left = -left;


        cout<<right<<" "<<left<<endl;

        vector<vector<int>> ans(right + left + 1);

        queue<pair<TreeNode*, int>> que;
        que.push(make_pair(root, left));

        while(!que.empty())
        {
            pair<TreeNode*, int> cur = que.front();
            que.pop();
            ans[cur.second].push_back(cur.first->val);
            if(cur.first->left)
                que.push(make_pair(cur.first->left, cur.second - 1));
            if(cur.first->right)
                que.push(make_pair(cur.first->right, cur.second + 1));

        }

        return ans;
    }
};