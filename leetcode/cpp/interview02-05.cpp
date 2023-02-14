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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        int pre = 0;
        ListNode dummy;
        ListNode* p = &dummy;
        while(l1 || l2)
        {
            int a = 0;
            int b = 0;
            if(l1)
            {
                a = l1->val;
                l1 = l1->next;
            }
            if(l2)
            {
                b = l2->val;
                l2 = l2->next;
            }
            int val = a + b + pre;
            pre = val / 10;
            p->next = new ListNode(val % 10);
            p = p->next;
        }
        if(pre)
            p->next = new ListNode(1);
        return dummy.next;
    }
};