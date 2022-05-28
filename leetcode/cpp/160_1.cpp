//链表相交

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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        int headA_length = 0;
        int headB_length = 0;
        ListNode* pA = headA;
        ListNode* pB = headB;

        while(pA)
        {
            pA = pA->next;
            ++headA_length;
        }
        while(pB)
        {
            pB = pB->next;
            ++headB_length;
        }

        ListNode* plong;
        ListNode* pshort;
        int detal = 0;
        if(headA_length > headB_length)
        {
            plong = headA;
            pshort = headB;
            detal = headA_length - headB_length;
        }
        else
        {
            plong = headB;
            pshort = headA;
            detal = headB_length - headA_length;
        }

        while(detal--)
        {
            plong = plong->next;
            //cout<<plong->val<<endl;
        }

        while(plong && pshort)
        {
            if(plong == pshort)
                return plong;
            plong = plong->next;
            pshort = pshort->next;
        }

        return NULL;
    }
};