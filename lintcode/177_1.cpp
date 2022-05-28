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
     * @param a: an integer array
     * @return: A tree node
     */
    TreeNode* sortedArrayToBST(vector<int> &a) {
        
        int n = a.size();
        if(n == 0)
            return NULL;
        else if(n == 1)
        {
            TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
            node->left = NULL;
            node->right = NULL;
            node->val = a[0];
            return node;
        }
        else
        {
            TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
            int mid = n / 2;
            vector<int> l{a.begin(), a.begin() + mid};
            node->left = sortedArrayToBST(l);
            vector<int> r{a.begin() + mid + 1, a.end()};
            node->right = sortedArrayToBST(r);
            node->val = a[mid];

            return node;
        }
    }
};