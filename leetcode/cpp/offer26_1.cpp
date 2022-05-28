//子树结构

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
private:
    bool ans = false;
public:
    bool isSameStructure(TreeNode* A, TreeNode* B)
    {
        if(!B)
            return true;
        if(!A)
            return false;
        if(A->val != B->val)
            return false;
        if(!isSameStructure(A->left, B->left))
            return false;
        if(!isSameStructure(A->right, B->right))
            return false;
        return true;
    }
    void dfs(TreeNode* A, TreeNode* B)
    {
        if(ans)
            return;
        if(isSameStructure(A, B))
        {
            ans = true;
            return ;
        }
        if(A->left)
            dfs(A->left, B);
        if(A->right)
            dfs(A->right, B);
    }
    bool isSubStructure(TreeNode* A, TreeNode* B) {

        if(!A || !B)
            return false;

        dfs(A, B);
        return ans;
    }
};