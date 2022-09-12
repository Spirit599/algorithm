// 148.排序链表

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

    ListNode* sortList(ListNode* head) {

    	ListNode dummy;
    	dummy.next = head;
    	ListNode* cur = head;

    	int length = 0;
    	while(cur)
    	{
    		++length;
    		cur = cur->next;
    	}

    	ListNode* prior = nullptr;
    	for(int cl = 1; cl < length; cl = cl * 2)
    	{
    		prior = &dummy;
    		while(prior)
    		{
 
	    		ListNode* ha = prior->next;
	    		if(!ha)
	    			break;

	    		ListNode* pa = ha;
	    		int la_len = 1;
	    		while(la_len != cl && pa && pa->next)
	    		{
	    			++la_len;
	    			pa = pa->next;
	    		}

	    		ListNode* hb = nullptr;
	    		ListNode* last = nullptr;
	    		if(pa)
	    		{
	    			last = pa;
	    			hb = pa->next;
	    			pa->next = nullptr;
	    		}
	    		ListNode* pb = hb;
	    		int lb_len = 1;
	    		while(lb_len != cl && pb && pb->next)
	    		{
	    			++lb_len;
	    			pb = pb->next;
	    		}


	    		ListNode* hc = nullptr;
	    		if(pb)
	    		{
	    			hc = pb->next;
	    			pb->next = nullptr;
	    			if(pb->val > pa->val)
	    				last = pb;
	    		}

	    		auto hm = merge(ha, hb);

	    		prior->next = hm;
	    		last->next = hc;

	    		prior = last;

	    	}
    	}

    	return dummy.next;


    }
    ListNode* merge(ListNode* la, ListNode* lb)
    {
    	ListNode head;
    	ListNode* p = &head;
    	while(la && lb)
    	{
    		if(la->val < lb->val)
    		{
    			p->next = la;
    			p = la;
    			la = la->next;
    		}
    		else
    		{
    			p->next = lb;
    			p = lb;
    			lb = lb->next;
    		}
    	}
    	if(la)
    		p->next = la;
    	else
    		p->next = lb;

    	return head.next;
    }
};