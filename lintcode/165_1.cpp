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
     * @param l1: ListNode l1 is the head of the linked list
     * @param l2: ListNode l2 is the head of the linked list
     * @return: ListNode head of linked list
     */
    ListNode* mergeTwoLists(ListNode *l1, ListNode *l2) {
        // write your code here

        ListNode* dummy = (ListNode*)malloc(sizeof(ListNode));
        dummy->next = NULL;
        ListNode* p = dummy;

        while(l1 && l2)
        {
            if(l1->val < l2->val)
            {
                p->next = l1;
                p = p->next;
                l1 = l1->next;
            }
            else
            {
                p->next = l2;
                p = p->next;
                l2 = l2->next;
            }
        }

        if(l1)
            p->next = l1;
        else
            p->next = l2;

        return dummy->next;

    }
};