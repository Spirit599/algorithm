
 
class Solution {
public:
    struct cur_p {
        //cur_p(ListNode* p1) {p = p1;}
        ListNode* ptr;
        bool operator < (const cur_p& rhs) const {
            return ptr->val > rhs.ptr->val;
        }
    };


    ListNode* mergeKLists(vector<ListNode*>& lists) {

        priority_queue<cur_p> pq;
        for(ListNode* list : lists)
            if(list)
                pq.push({list});

        ListNode head;
        head.next = nullptr;
        ListNode* p = &head;

        while(!pq.empty())
        {
            cur_p cur = pq.top();
            cout<<cur.ptr->val<<endl;
            pq.pop();

            p->next = cur.ptr;
            p = cur.ptr;

            if(p->next)
                pq.push({p->next});
        }



        return head.next;
    }
};

