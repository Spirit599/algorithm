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
    ListNode* removeDuplicateNodes(ListNode* head) {

        if(!head)
            return NULL;

        unordered_set<int> memo;
        ListNode* p = head;
        memo.insert(p->val);

        while(p->next)
        {
            if(memo.find(p->next->val) != memo.end())
            {
                p->next = p->next->next;
            }
            else
            {
                memo.insert(p->next->val);
                p = p->next;
            }
        }

        return head;
    }
};