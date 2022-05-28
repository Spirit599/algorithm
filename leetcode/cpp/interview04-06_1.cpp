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
    
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {

        // if(p->right)
        // {
        //     p = p->right;
        //     while(p->left)
        //     {
        //         p = p->left;
        //     }
        //     return p;
        // }

        // TreeNode* ans = NULL;
        // while(root != p)
        // {
        //     if(root->val > p->val)
        //     {
        //         ans = root;
        //         root = root->left;
        //     }
        //     else
        //     {
        //         root = root->right;
        //     }
        // }
        // return ans;

        stack<TreeNode*> st;
        TreeNode* q = root;
        bool find = false;
        //TreeNode* ans = NULL;
        while(q || !st.empty())
        {
            if(q)
            {
                st.push(q);
                q = q->left;
            }
            else
            {
                q = st.top();
                cout<<q->val<<endl;
                if(find)
                    return q;
                if(q == p)
                    find = true;
                st.pop();
                q = q->right;
            }
        }

        return NULL;
    }
};