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
    int numComponents(ListNode* head, vector<int>& nums) {

        unordered_set memo(nums.begin(), nums.end());
        int ans = 0;

        ListNode* p = head;
        bool preIsComp = false;
        while(p) 
        {
            if(memo.count(p->val))
            {
                if(!preIsComp)
                {
                    ++ans;
                    preIsComp = true;
                }
            }
            else
            {
                preIsComp = false;
            }
            p = p->next;
        }

        return ans;
    }
};