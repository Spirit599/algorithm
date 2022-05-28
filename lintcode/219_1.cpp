/**
 * Definition of singly-linked-list:
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *        this->val = val;
 *        this->next = NULL;
 *     }
 * }
 */

class Solution {
public:
    /**
     * @param head: The head of linked list.
     * @param val: An integer.
     * @return: The head of new linked list.
     */
    ListNode* insertNode(ListNode *head, int val) {
        
        ListNode* add = (ListNode*)malloc(sizeof(ListNode));
        add->val = val;
        add->next = NULL;

        ListNode* p = head;
        if(p == NULL)
            return add;
        if(val < p->val)
        {
            add->next = p;
            return add;
        }


        while(p->next && p->next->val < val)
        {
            p = p->next;
        }

        add->next = p->next;
        p->next = add;

        return head;
    }
};