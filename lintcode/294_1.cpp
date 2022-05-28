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
     * @param head: the linked list to be simplify.
     * @return: return the linked list after simplifiction.
     */
    ListNode* simplify(ListNode *head) {
        
        int n = 0;
        ListNode* p = head;
        ListNode* last = NULL;
        ListNode* r = NULL;
        while(p)
        {
            ++n;
            if(p->next == NULL)
                last = p;
            p = p->next;
            
        }


        if(n <= 2)
            return head;

        p = head->next;
        string str_num = to_string(n - 2);
        for(char c : str_num)
        {
            p->val = c;
            r = p;
            p = p->next;
        }

        r->next = last;
        return head;
    }
};