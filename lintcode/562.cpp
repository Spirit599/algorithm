// 562 · 背包问题 IV

class Solution {
public:
    /**
     * @param nums: an integer array and all positive numbers, no duplicates
     * @param target: An integer
     * @return: An integer
     */
    int backPackIV(vector<int> &nums, int target) {
        
        int dp[target + 1];
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;
        int n = nums.size();

        // for(int w = 0; w <= target; ++w)
        // {
        //     for(int i = 0; i < n; ++i)
        //     {
        //         if(w - nums[i] >= 0)
        //             dp[w] += dp[w - nums[i]];
        //     }
        //     cout<<w<<" "<<dp[w]<<endl;
        // }
        for(int i = 0; i < n; ++i)
        {
            for(int w = 0; w <= target; ++w)
            {
                if(w - nums[i] >= 0)
                     dp[w] += dp[w - nums[i]];
            }
        }
        return dp[target];
    }
};