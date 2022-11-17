class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {

        int ans = 0;
        int n = nums.size();
        int cur = 1;
        int left = -1;
        for(int right = 0; right < n; ++right)
        {
            cur *= nums[right];
            while(left != right && cur >= k)
                cur /= nums[++left];
            ans += right - left;
        }
        return ans;
    }
};