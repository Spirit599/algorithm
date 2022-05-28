/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {

        stack<Node *> NodeStack;
        
        Node *p = head;

        while(p)
        {
            //cout<<p->val<<endl;
            while(p->child)
            {
                if(p->next)
                {
                    NodeStack.push(p->next);
                }
                Node *r = p->child;
                p->child = NULL;
                r->prev = p;
                p->next = r;
                p = r;
            }

            while(!p->next && !NodeStack.empty())
            {
                Node *r = NodeStack.top();
                NodeStack.pop();
                r->prev = p;
                p->next = r;
                p = r;
            }

            p = p->next;
        }

        return head;
    }
};