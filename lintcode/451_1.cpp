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
     * @return: a ListNode
     */
    ListNode* swapPairs(ListNode *head) {
        
        ListNode* dummy = (ListNode*)malloc(sizeof(ListNode));
        dummy->next = head;

        ListNode* p = dummy;

        while(p->next && p->next->next)
        {
            ListNode* r = p->next;
            p->next = p->next->next;
            r->next = p->next->next;
            p->next->next = r;

            p = p->next->next;
        }

        return dummy->next;
    }
};