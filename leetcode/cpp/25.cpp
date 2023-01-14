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
	pair<ListNode*, ListNode*> reverse(ListNode* p) {

		ListNode* prev = nullptr;
		ListNode* last = p;
		while(p)
		{
			ListNode* r = p->next;
			p->next = prev;
			prev = p;
			p = r;
		}

		return make_pair(prev, last);
	}
    ListNode* reverseKGroup(ListNode* head, int k) {

    	ListNode dummy;
    	dummy.next = head;
    	ListNode* prevHead = &dummy;
    	ListNode* p = head;

    	while(1)
    	{
    		ListNode* rep = p;
    		for(int i = 0; i < k - 1; ++i)
    		{
    			if(p)
    			{
    				p = p->next;
    			}
    			else
    			{
    				prevHead->next = rep;
    				return dummy.next;
    			}
    		}
    		if(!p)
    		{
    			prevHead->next = rep;
    			return dummy.next;
    		}
    		ListNode* r = p->next;
    		p->next = nullptr;

    		auto [start, end] = reverse(rep);
    		prevHead->next = start;
    		prevHead = end;
    		p = r;
    	}

    	return dummy.next;
    }
};