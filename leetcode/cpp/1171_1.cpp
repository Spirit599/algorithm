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
//前缀和
//链表

class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {

        if(!head)
            return head;

        ListNode* dummy = (ListNode*)malloc(sizeof(ListNode));
        dummy->next = head;
        dummy->val = 0;
        ListNode* p = dummy;


        unordered_map<int, ListNode*> um;

        int presum = 0;
        while(p)
        {
            presum += p->val;
            //cout<<presum<<endl;
            if(um.count(presum) != 0)
            {
                ListNode* q = um[presum];
                ListNode* temp = q->next;
                int temp_presum = presum;
                q->next = p->next;

                while(temp != p)
                {
                    temp_presum += temp->val;
                    um.erase(temp_presum);
                    temp = temp->next;
                }

                
            }
            else
            {
                um[presum] = p;
            } 
            p = p->next;
        }

        return dummy->next;

    }
};