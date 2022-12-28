class Solution {
public:
    int minimumWhiteTiles(string floor, int numCarpets, int carpetLen) {
        
        int n = floor.size();
        int preSum[n + 1];
        preSum[0] = 0;
        for(int i = 0; i < n; ++i)
        {
            if(floor[i] == '1')
                preSum[i + 1] = preSum[i] + 1;
            else
                preSum[i + 1] = preSum[i];
        }

        int dp[n + 1][numCarpets + 1];
        memset(dp, 0, sizeof(dp));
        
        for(int i = 0; i < n; ++i)
        {
            for(int j = 1; j <= numCarpets; ++j)
            {
                int right = i;
                int left = max(i - carpetLen + 1, 0);
                dp[i + 1][j] = max(dp[i][j], dp[left][j - 1] + preSum[right + 1] - preSum[left]);

            }
        }

        return preSum[n] - dp[n][numCarpets];

    }
};