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
    // bool nodeIsSame(TreeNode* p1, TreeNode* p2) {

    //     if(!p1 && !p2)
    //         return true;
    //     else if(!p1 && p2)
    //         return false;
    //     else if(p1 && !p2)
    //         return false;
    //     else if(p1->val == p2->val)
    //         return true;
    //     else
    //         return false;
    // }
    // bool dfs(TreeNode* p1, TreeNode* p2) {

    //     TreeNode* p1Left = p1->left;
    //     TreeNode* p1Right = p1->right;
    //     TreeNode* p2Left = p2->left;
    //     TreeNode* p2Right = p2->right;



    // }
    bool flipEquiv(TreeNode* p1, TreeNode* p2) {

        if(!p1 && !p2)
            return true;
        else if(!p1 && p2)
            return false;
        else if(p1 && !p2)
            return false;
        else if(p1->val != p2->val)
            return false;

        return (flipEquiv(p1->left, p2->left) && flipEquiv(p1->right, p2->right)) || 
                (flipEquiv(p1->left, p2->right) && flipEquiv(p1->right, p2->left)); 
    }
};