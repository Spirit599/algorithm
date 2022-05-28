/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

//层序遍历

class Solution {
public:
    Node* connect(Node* root) {

        if(!root)
            return NULL;

        queue<Node*> que;
        que.push(root);

        while(!que.empty())
        {
            int len = que.size();
            while(len--)
            {
                Node* cur = que.front();
                cout<<cur->val<<endl;
                que.pop();
                if(cur->left)
                    que.push(cur->left);
                if(cur->right)
                    que.push(cur->right);
                if(len != 0)
                    cur->next = que.front();
                else
                    cur->next = NULL;
            }
        }

        return root;
    }
};