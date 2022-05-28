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
private:
    long long ret = 0;
public:
    void for_each_path_length(TreeNode* node, int targetSum)
    {
        TreeNode* p = node;
        stack<TreeNode*> tree_stack;


        while(p || !tree_stack.empty())
        {
            if(p)
            {   
                cout<<p->val<<" "<<targetSum<<endl;
                if(p->val == targetSum)
                    ret++;

                tree_stack.push(p);
                p = p->left;
 

            }
            else
            {
                p  = tree_stack.top();
                tree_stack.pop();
                p = p->right;

            }
        }

    }

    void dfs(TreeNode* root, int targetSum)
    {
        if(!root)
            return;

        for_each_path_length(root, targetSum);
        cout<<"--------------"<<endl;
        dfs(root->left, targetSum + root->val);
        dfs(root->right, targetSum + root->val);

    }


    int pathSum(TreeNode* root, int targetSum) {

        if(!root)
            return 0;

        queue<TreeNode*> treeq;
        treeq.push(root);
        TreeNode* presum_root;

        while(!treeq.empty())
        {
            TreeNode* p = treeq.front();
            if(p->left) {

                p->left->val += p->val;
                treeq.push(p->left);
            }
            if(p->right){

                p->right->val += p->val;
                treeq.push(p->right);
            }
            treeq.pop();

        }

        dfs(root, targetSum);

        return ret;

    }
};