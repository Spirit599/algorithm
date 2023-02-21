class Solution {
public:
    int helper(vector<int>& nums, int k) {

        int n = nums.size();
        int ans = 0;
        int left = 0;
        int cnt = 0;
        for(int right = 0; right < n; ++right)
        {
            cnt += nums[right] & 1;
            while(cnt > k)
            {
                cnt -= nums[left] & 1;
                ++left;
            }
            
            ans += right - left + 1;
        }
        return ans;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {

        return helper(nums, k) - helper(nums, k - 1);
    }
};