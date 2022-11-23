class Solution {
public:
    int robHelper(vector<int>& nums, int left, int right) {

        int dp1 = nums[left];
        int dp2 = 0;
        for(int i = left + 1; i <= right; ++i)
        {
            int ndp1 = dp2 + nums[i];
            int ndp2 = max(dp1, dp2);
            dp1 = ndp1;
            dp2 = ndp2;
        }
        return max(dp1, dp2);
    }
    int rob(vector<int>& nums) {

        int n = nums.size();
        if(n == 1)
            return nums[0];
        return max(robHelper(nums, 0, n - 2), robHelper(nums, 1, n - 1));
    }
};