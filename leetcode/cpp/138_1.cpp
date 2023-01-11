/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    unordered_map<Node*, Node*> originToCopy;
    Node* copyRandomList(Node* head) {
        
        if(!head)
            return nullptr;

        auto it = originToCopy.find(head);
        if(it == originToCopy.end())
        {
            Node* newNode = new Node(head->val);
            originToCopy[head] = newNode;
            newNode->next = copyRandomList(head->next);
            newNode->random = copyRandomList(head->random);
            return newNode;
        }
        else
        {
            return it->second;
        }
    }
};