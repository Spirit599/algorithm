/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;

    Node() {}

    Node(int _val) {
        val = _val;
        next = NULL;
    }

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};
*/

class Solution {
public:
    Node* insert(Node* head, int insertVal) {
        
        Node* ne = new Node(insertVal);

        if(head == nullptr)
        {
            ne->next = ne;
            return ne;
        }
        // if(head == head->next)
        // {
        //     ne->next = head;
        //     head->next = ne;
        //     return head;
        // }

        Node* p = head;
        Node* next = p->next;

        while(next != head)
        {
            if(p->val <= insertVal && insertVal <= p->next->val)
            {
                break;
            }
            if(p->val > p->next->val && (insertVal >= p->val || insertVal <= p->next->val))
            {
                break;
            }
            p = next;
            next = next->next;
        }
        ne->next = p->next;
        p->next = ne;

        return head;
    }
};