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
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        int n = lists.size();
        if(n == 0)
            return nullptr;

        return merge(lists, 0, n - 1);
    }
    ListNode* merge(vector<ListNode*>& lists, int left, int right)
    {
        if(left == right)
            return lists[left];
        int mid = (left + right) >> 1;
        return mergeDoubleLists(merge(lists, left, mid), merge(lists, mid + 1, right));
    }

    ListNode* mergeDoubleLists(ListNode* la, ListNode* lb)
    {
        ListNode dummy;
        ListNode *p = &dummy;
        while(la && lb)
        {
            if(la->val < lb->val)
            {
                p->next = la;
                la = la->next;
            }
            else
            {
                p->next = lb;
                lb = lb->next;
            }
            p = p->next;
        }
        if(la)
            p->next = la;
        else
            p->next = lb;
        return dummy.next;
    }
};