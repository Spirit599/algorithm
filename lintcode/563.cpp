// 563 · 背包问题 V

class Solution {
public:
    /**
     * @param nums: an integer array and all positive numbers
     * @param target: An integer
     * @return: An integer
     */
    int backPackV(vector<int> &nums, int target) {
        
        int dp[target + 1];
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;
        int n = nums.size();

        for(int i = 0; i < n; ++i)
        {
            for(int w = target; w >= nums[i]; --w)
            {
                dp[w] += dp[w - nums[i]];
                cout<<w<<" "<<dp[w]<<"|";
            }
            cout<<endl;
        }

        return dp[target];
    }
};