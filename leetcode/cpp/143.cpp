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
    ListNode* getMidPtr(ListNode* head) {
        
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast)
        {
            fast = fast->next;
            if(!fast)
                break;
            fast = fast->next;
            slow = slow->next;
        }
        return slow;
    }
    ListNode* reverseList(ListNode* head) {

        ListNode* prev = nullptr;
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
    ListNode* mergeList(ListNode* h1, ListNode* h2) {

        ListNode* p1 = h1;
        ListNode* p2 = h2;
        ListNode* dummy = new ListNode();
        ListNode* p = dummy;
        while(p1 && p2)
        {
            if(p1)
            {
                p->next = p1;
                p = p->next;
                p1 = p1->next;
            }
            if(p2)
            {
                p->next = p2;
                p = p->next;
                p2 = p2->next;
            }
        }
        p->next = nullptr;
        return dummy->next;
    }
    void reorderList(ListNode* head) {

        ListNode* mid = getMidPtr(head);
        ListNode* h2 = reverseList(mid);
        ListNode* h1 = head;
        ListNode* h = mergeList(h1, h2);
    }
};