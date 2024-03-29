class Solution {
public:
    int smallestRangeII(vector<int>& nums, int k) {

        int n = nums.size();
        sort(nums.begin(), nums.end());
        int ans = nums[n - 1] - nums[0];

        for(int i = 0; i < n - 1; ++i)
        {
            int high = max(nums[n - 1] - k, nums[i] + k);
            int low = min(nums[0] + k, nums[i + 1] - k);

            ans = min(ans, high - low);
        }

        return ans;
    }
};