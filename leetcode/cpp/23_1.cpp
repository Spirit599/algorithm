// 23. 合并K个升序链表
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
        int mid = (right - left) / 2 + left;

        return mergeTwoLists(merge(lists, left, mid), merge(lists, mid + 1, right));
    }

    ListNode* mergeTwoLists(ListNode* la, ListNode* lb)
    {
        ListNode head;
        ListNode* p = &head;
        ListNode* pa = la;
        ListNode* pb = lb;

        while(pa && pb)
        {
            if(pa->val < pb->val)
            {
                p->next = pa;
                pa = pa->next;
            }
            else
            {
                p->next = pb;
                pb = pb->next;
            }
            p = p->next;
        }

        if(pa)
            p->next = pa;
        else
            p->next = pb;

        return head.next;
    }


};