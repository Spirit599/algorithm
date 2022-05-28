/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
private:
    vector<int> ans;
public:
    void dfs(ListNode* head)
    {
        if(head)
        {
            dfs(head->next);
            ans.push_back(head->val);
        }
    }
    vector<int> reversePrint(ListNode* head) {
        
        dfs(head);
        return ans;
    }
};