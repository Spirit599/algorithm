// 105. 从前序与中序遍历序列构造二叉树

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
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, 
                    int preleft, int preright,
                    int inleft, int inright) {

        if(preleft > preright)
            return nullptr;

        int val = preorder[preleft];
        cout<<val<<endl;
        TreeNode* cur = new TreeNode(val);
        int split = -1;
        for(int i = inleft; i <= inright; ++i)
        {
            if(inorder[i] == val)
            {
                split = i;
                break;
            }
        }
        int leftnum = split - inleft;
        int rightnum = inright - split;

        TreeNode* pleft = build(preorder, inorder, preleft + 1, preleft + 1 + leftnum - 1,
                                                    inleft, inleft + leftnum - 1);
        TreeNode* pright = build(preorder, inorder, preright - rightnum + 1, preright,
                                                    inright - rightnum + 1, inright);
        cur->left = pleft;
        cur->right = pright;

        return cur;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

        return build(preorder, inorder, 0, preorder.size() - 1 , 0, inorder.size() - 1);
    }
};