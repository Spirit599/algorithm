class Solution {
public:
    bool validPartition(vector<int>& nums) {
        
        int n = nums.size();
        if(n < 2)
            return false;

        bool dp[n + 1];
        memset(dp, 0, sizeof(dp));
        dp[0] = true;

        for(int i = 1; i < n; ++i) {

            if(i - 2 >= -1 && nums[i] == nums[i - 1] && dp[i - 1])
                dp[i + 1] |= true;
            if(i - 3 >= -1 && nums[i] == nums[i - 1] && nums[i] == nums[i - 2] && dp[i - 2])
                dp[i + 1] |= true;
            if(i - 3 >= -1 && nums[i] == nums[i - 1]  + 1 && nums[i] == nums[i - 2] + 2 && dp[i - 2])
                dp[i + 1] |= true;
        }

        return dp[n];
    }
};