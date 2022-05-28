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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {


        int head_len = 0;
        struct ListNode *p = head;
        while(p)
        {
            ++head_len;
            p = p->next;
        }

        vector<ListNode*> ret;
        int kk = k;
        struct ListNode *start = head;
        struct ListNode *end = head;

        while(k--)
        {

            int step_size = 0;

            if(head_len % kk == 0)
            {
                step_size = head_len / kk;
            }
            else
            {
                step_size = head_len / kk + 1;
            }
            
            cout<<step_size<<endl;
            head_len -= step_size;
            kk--;
            while(step_size-- >= 2)
            {
                if(end)
                    end = end->next;

            }

            if(end){
                p = end->next;
                end->next = NULL;
            }

            ret.push_back(start);
            start = p;
            end = start;

        }

        return ret;

    }
};