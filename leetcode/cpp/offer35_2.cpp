// 递归 复制
// hash

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
    unordered_map<Node*, Node*> um;
    Node* copyRandomList(Node* head) {
        
        if(!head)
            return NULL;

        if(um.count(head) != 1)
        {
            Node* head_copy = (Node*)malloc(sizeof(Node));
            head_copy->val = head->val;
            um[head] = head_copy;
            head_copy->next = copyRandomList(head->next);
            head_copy->random = copyRandomList(head->random);
        }

        return um[head];
    }
};