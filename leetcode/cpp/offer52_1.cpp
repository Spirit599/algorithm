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
        
        ListNode* pA = headA;
        int lenA = 0;
        while(pA)
        {
            ++lenA;
            pA = pA->next;
        }

        ListNode* pB = headB;
        int lenB = 0;
        while(pB)
        {
            ++lenB;
            pB = pB->next;
        }

        int detal = lenA - lenB;
        pA = headA;
        pB = headB;
        if(detal >= 0)
        {
            while(detal--)
            {
                pA = pA->next;
            }
            while(pA)
            {
                if(pA == pB)
                    return pA;
                pA = pA->next;
                pB = pB->next;
            }
        }
        else
        {
            detal = -detal;
            while(detal--)
            {
                pB = pB->next;
            }
            while(pA)
            {
                if(pA == pB)
                    return pA;
                pA = pA->next;
                pB = pB->next;
            }
        }

        return NULL;
    }
};