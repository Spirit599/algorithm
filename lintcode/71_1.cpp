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

//71 · 二叉树的锯齿形层次遍历

class Solution {
public:
    /**
     * @param root: A Tree
     * @return: A list of lists of integer include the zigzag level order traversal of its nodes' values.
     */
    vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
        
        vector<vector<int>> ans;
        if(root == nullptr)
            return ans;

        queue<TreeNode*> que;
        que.push(root);
        bool reverse_arr = false;

        while(!que.empty())
        {
            vector<int> arr;
            int k = que.size();
            while(k--)
            {
                TreeNode* cur = que.front();
                que.pop();
                arr.push_back(cur->val);
                if(cur->left)
                    que.push(cur->left);
                if(cur->right)
                    que.push(cur->right);

            }
            if(reverse_arr)
                reverse(arr.begin(), arr.end());
            ans.push_back(std::move(arr));
            reverse_arr = !reverse_arr;
        }

        return ans;
    }
};