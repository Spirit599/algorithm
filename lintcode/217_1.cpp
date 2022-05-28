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
     * @param head: The first node of linked list.
     * @return: Head node.
     */
    ListNode* removeDuplicates(ListNode *head) {
        
        if(head == NULL)
            return NULL;

        unordered_set<int> memo;
        ListNode* p = head;

        while(p->next)
        {
            memo.insert(p->val);
            if(memo.count(p->next->val) == 1)
            {
                p->next = p->next->next;
            }
            else
            {
                p = p->next;
            }
        }

        return head;
    }
};