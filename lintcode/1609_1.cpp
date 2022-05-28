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
     * @return: a middle node of the linked list
     */
    ListNode* middleNode(ListNode *head) {
        
        ListNode* fast = head;
        ListNode* slow = head;

        while(fast)
        {
            fast = fast->next;
            if(fast)
                fast = fast->next;
            else
                return slow;
            
            slow = slow->next;
        }

        return slow;
    }
};