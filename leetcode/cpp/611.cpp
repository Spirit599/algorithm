class Solution {
public:
    int triangleNumber(vector<int>& nums) {

        sort(nums.begin(), nums.end());
        int ans = 0;
        int n = nums.size();
        for(int i = 0; i < n; ++i)
        {
            for(int j = i + 1; j < n; ++j)
            {
                int low = nums[j] - nums[i] + 1;
                int high = nums[j] + nums[i] - 1;
                if(low > high)
                    continue;
                auto itBegin = nums.begin() + j + 1;
                auto itHigh = upper_bound(itBegin, nums.end(), high);
                auto itLow = lower_bound(itBegin, nums.end(), low);
                ans += itHigh - itLow;
            }
        }
        return ans;
    }
};