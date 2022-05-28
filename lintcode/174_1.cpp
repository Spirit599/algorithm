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
     * @param head: The first node of linked list.
     * @param n: An integer
     * @return: The head of linked list.
     */
    ListNode* removeNthFromEnd(ListNode *head, int n) {
        
        ListNode* fast = head;
        ListNode* slow = head;

        while(n--)
        {
            fast = fast->next;
        }
        if(fast == NULL)
        {
            return head->next;
        }

        while(fast)
        {
            fast = fast->next;
            if(fast != NULL)
                slow = slow->next;
            else
                slow->next = slow->next->next;
        }

        return head;
    }
};