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
     * @param head: the head of linked list.
     * @param val: An integer.
     * @return: a linked node or null.
     */
    ListNode* findNode(ListNode *head, int val) {
        
        ListNode* p = head;

        while(p)
        {
            if(p->val == val)
                return p;

            p = p->next;
        }

        return NULL;
    }
};