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
    ListNode* deleteNode(ListNode* head, int val) {

        ListNode* p = head;
        while(p && p->val == val)
            p = p->next;

        head = p;
        if(!head)
            return NULL;

        while(p->next)
        {
            if(p->next->val == val)
            {
                p->next = p->next->next;
                return head;
            }
            else
            {
                p = p->next;
            }
        }

        return head;
    }
};