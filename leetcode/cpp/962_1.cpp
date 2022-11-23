class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {

        int n = nums.size();
        vector<int> stk;
        stk.emplace_back(0);
        for(int i = 1; i < n; ++i)
        {
            if(nums[stk.back()] > nums[i])
            {
                stk.emplace_back(i);
            }
        }

        int ptr = stk.size() - 1;
        int ans = 0;
        for(int i = n - 1; i >= 0; --i)
        {
            while(ptr >= 0 && nums[stk[ptr]] <= nums[i])
            {
                ans = max(ans, i - stk[ptr]);
                --ptr;
                if(ptr == -1)
                    return ans;
            }
        }

        return ans;

    }
};