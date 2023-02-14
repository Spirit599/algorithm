class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        
        sort(nums.begin(), nums.end());
        long long ans = 0;
        int n = nums.size();

        for(int i = 0; i < n; ++i)
        {
            int ll = lower - nums[i] - 1;
            int rr = upper - nums[i];
            auto it1 = upper_bound(nums.begin(), nums.end(), ll);
            auto it2 = upper_bound(nums.begin(), nums.end(), rr);
            int ret = it2 - it1;
            if(ll < nums[i] && nums[i] <= rr)
                --ret;
            ans += ret;
        }

        return ans >> 1;
    }
};