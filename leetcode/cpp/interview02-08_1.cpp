/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        
        if(!head)
            return NULL;

        ListNode* fast = head->next;
        ListNode* slow = head->next;
        if(fast)
            fast = fast->next;

        while(fast)
        {
            if(fast == slow)
            {
                break;
            }
            fast = fast->next;
            slow = slow->next;
            if(fast)
                fast = fast->next;
        }
        if(!fast)
            return NULL;

        ListNode* start = head;
        while(start != fast)
        {
            start = start->next;
            fast = fast->next;
        }
        return fast;
    }
};