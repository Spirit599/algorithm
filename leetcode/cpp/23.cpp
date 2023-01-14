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
	ListNode* mergeDoubleList(ListNode* l1, ListNode* l2) {

		ListNode dummy;
    	ListNode* p = &dummy;

    	while(l1 && l2)
    	{
    		if(l1->val < l2->val)
    		{
    			p->next = l1;
    			l1 = l1->next;
    		}
    		else
    		{
    			p->next = l2;
    			l2 = l2->next;
    		}
    		p = p->next;
    	}
    	if(l1)
    		p->next = l1;
    	else
    		p->next = l2;

    	return dummy.next;
	}

	ListNode* merge(vector<ListNode*>& lists, int left, int right)
	{
		if(left == right)
			return lists[left];
		int mid = (left + right) / 2;
		return mergeDoubleList(merge(lists, left, mid), merge(lists, mid + 1, right));
	}

    ListNode* mergeKLists(vector<ListNode*>& lists) {

    	int n = lists.size();
    	if(n == 0)
    		return nullptr;

    	return merge(lists, 0, n - 1);
    }
};