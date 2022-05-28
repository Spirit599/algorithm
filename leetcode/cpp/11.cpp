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
    ListNode* deleteMiddle(ListNode* head) {
        
        ListNode* p = head;
        int len = 0;
        while(p)
        {
            p = p->next;
            ++len;
        }
        if(len == 0 || len == 1)
            return NULL;
        len = len / 2;
        int k = 0;

        p = head;
        while(k < len - 1)
        {
            cout<<p->val<<endl;
            p = p->next;
            ++k;
        }
        p->next = p->next->next;

        return head;
    }
};