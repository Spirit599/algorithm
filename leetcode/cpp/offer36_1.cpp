/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/
class Solution {
public:
    Node* head = NULL;
    Node* prev = NULL;
    void dfs(Node* cur)
    {
        if(!cur)
            return ;
        dfs(cur->left);
        if(prev == NULL)
            head = cur;
        else
            prev->right = cur;
        cur->left = prev;
        prev = cur;
        dfs(cur->right);
    }
    Node* treeToDoublyList(Node* root) {
        
        if(!root)
            return NULL;
        dfs(root);
        head->left = prev;
        prev->right = head;
        return head;
    }
};