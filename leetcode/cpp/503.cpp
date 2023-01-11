class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {

        int n = nums.size();
        nums.insert(nums.end(), nums.begin(), nums.end());
        vector<int> ans(n, -1);

        vector<int> stk;
        for(int i = 0; i < 2 * n; ++i)
        {
            while(!stk.empty() && nums[stk.back()] < nums[i])
            {
                if(stk.back() < n)
                    ans[stk.back()] = nums[i];
                stk.pop_back();
            }
            stk.push_back(nums[i]);
        }

        return ans;
    }
};