// 416. 分割等和子集

class Solution {
public:
    bool canPartition(vector<int>& nums) {

        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum & 1)
            return false;

        int tagret = sum >> 1;

        bool dp[n + 1][tagret + 1];
        memset(dp, 0, sizeof(dp));

        dp[0][0] = true;
        for(int i = 0; i < n; ++i)
        {
            memcpy(dp[i + 1], dp[i], sizeof(dp[i + 1]));
            for(int j = 0; j <= tagret; ++j)
            {
                int k = nums[i];
                if(j + k >= 0 && j + k <= tagret)
                    dp[i + 1][j + k] |= dp[i][j];
            }

            if(dp[i + 1][tagret] == true)
                return true;
        }

        return false;
    }
};