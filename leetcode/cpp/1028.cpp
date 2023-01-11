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
    TreeNode* recoverFromPreorder(string traversal) {

        vector<TreeNode*> stk;

        int i = 0;
        int n = traversal.size();
        while(i < n)
        {
            int level = 0;
            while(i < n && traversal[i] == '-')
            {
                ++i;
                ++level;
            }
            int val = 0;
            while(i < n && isdigit(traversal[i]))
            {
                val = 10 * val + traversal[i] - '0';
                ++i;
            }

            TreeNode *p = new TreeNode(val);
            if(stk.size() == level)
            {
                if(!stk.empty())
                    stk.back()->left = p;
            }
            else
            {
                while(stk.size() != level)
                    stk.pop_back();
                stk.back()->right = p;
            }
            stk.emplace_back(p);
        }

        while(stk.size() != 1)
            stk.pop_back();

        return stk.back();


    }
};