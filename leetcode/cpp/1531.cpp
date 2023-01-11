class Solution {
public:
    int getLengthOfOptimalCompression(string s, int k) {

        int n = s.size();
        int dp[n + 1][k + 1];
        memset(dp, 0, sizeof(dp));


        for(int i = 0; i < n; ++i)
        {
            for(int j = 1; j <= k; ++j)
            {
                dp[i + 1][j] = 
            }
        }


        return dp[n][k];
    }
};