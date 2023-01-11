/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {

        ListNode dummyEven;
        ListNode* pd = &dummyEven;
        ListNode* p = head;
        ListNode* r = p;
        bool isEven = false;

        while(p && p->next)
        {
            // printf("%d\n", p->val);
            pd->next = p->next;
            pd = pd->next;
            r = p;
            p->next = p->next->next;
            p = p->next;
            pd->next = nullptr;
        }

        // printf("%d\n", r->val);
        while(r && r->next)
            r = r->next;
        // printf("%d\n", r->val);
        if(r)
            r->next = dummyEven.next;

        return head;
    }
};