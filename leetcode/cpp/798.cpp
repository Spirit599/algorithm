class Solution {
public:
    int bestRotation(vector<int>& nums) {
        
        int n = nums.size();
        int score = 0;
        int dp[n + 1];
        memset(dp, 0, sizeof(dp));
        for(int i = 0; i < n; ++i)
        {
            if(i - nums[i] >= 0)
            {
                ++dp[i - nums[i]];
                ++score;
            }
        }


        int index = 0;
        int ans = score;
        for(int i = 0; i < n; ++i)
        {
            int dif = i - nums[i];
            if(dif < i)
                ++score;
            if(dif < 0)
                ++dp[dif + n];
            else
                --dp[dif];
            score -= dp[i];
            if(score > ans)
            {
                ans = score;
                index = i + 1;
            }
        }

        return index;
    }
};