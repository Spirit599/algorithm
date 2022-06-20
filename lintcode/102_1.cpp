// 102 · 带环链表

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
     * @return: True if it has a cycle, or false
     */
    bool hasCycle(ListNode * head) {
        
        if(head == nullptr)
        	return false;

        ListNode* fast = head->next;
        ListNode* slow = head;

        while(fast)
        {
        	if(fast == slow)
        		return true;
        	fast = fast->next;
        	if(fast)
        		fast = fast->next;
        	slow = slow->next;
        }

        return false;

    }
};