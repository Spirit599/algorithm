class Solution {
public:
    int maximumGap(vector<int>& nums) {

        int ans = 0;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for(int i = 1; i < n; ++i)
            ans = max(ans, nums[i] - nums[i - 1]);

        return ans;
    }
};