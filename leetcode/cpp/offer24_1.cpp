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
    ListNode* reverseList(ListNode* head) {

        // ListNode* dummy = (ListNode*)malloc(sizeof(ListNode));
        // dummy->next = NULL;
        ListNode* prev = NULL;
        ListNode* p = head;
        while(p)
        {
            ListNode* r = p->next;
            p->next = prev;
            prev = p;
            p = r;
        }

        return prev;

    }
};