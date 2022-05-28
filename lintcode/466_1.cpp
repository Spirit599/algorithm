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
     * @param head: the first node of linked list.
     * @return: An integer
     */
    int countNodes(ListNode *head) {
        
        int ans = 0;
        ListNode* p = head;

        while(p)
        {
            ++ans;
            p = p->next;
        }

        return ans;
    }
};