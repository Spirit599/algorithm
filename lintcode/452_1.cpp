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
     * @param head: a ListNode
     * @param val: An integer
     * @return: a ListNode
     */
    ListNode* removeElements(ListNode *head, int val) {
        
        ListNode* dummy = (ListNode*)malloc(sizeof(ListNode));
        dummy->next = head;

        ListNode* p = dummy;

        while(p->next)
        {
            if(p->next->val == val)
            {
                p->next = p->next->next;
            }
            else
            {
                p = p->next;
            }
        }

        return dummy->next;
    }
};