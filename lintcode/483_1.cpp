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
     * @param head: the head of linked list.
     * @return: An integer list
     */
    vector<int> toArrayList(ListNode *head) {
        
        vector<int> ans;
        ListNode* p = head;

        while(p)
        {
            ans.emplace_back(p->val);
            p = p->next;
        }

        return ans;
    }
};