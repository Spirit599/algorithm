//单调栈
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {

        vector<int> ans;
        stack<int> stk;
        unordered_map<int, int> um;
        for(auto num : nums2)
        {
            while(!stk.empty() && stk.top() < num)
            {
                um[stk.top()] = num;
                stk.pop();
            }
            stk.push(num);
        }

        while(!stk.empty())
        {
            um[stk.top()] = -1;
            stk.pop();
        }

        for(auto num : nums1)
        {
            ans.push_back(um[num]);
        }

        return ans;
    }
};