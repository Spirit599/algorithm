// 轮盘
// 动态规划

class Solution {
public:
    int findRotateSteps(string ring, string key) {

        int keySize = key.size();
        int ringSize = ring.size();
        int dp[keySize + 1][ringSize];
        memset(dp, 0x3f, sizeof(dp));
        dp[0][0] = 0;
        
        for(int i = 0; i < keySize; ++i)
        {
            for(int j = 0; j < ringSize; ++j)
            {
                if(dp[i][j] == 0x3f3f3f3f)
                    continue;
                for(int k = 0; k < ringSize; ++k)
                {
                    if(ring[k] != key[i])
                        continue;
                    //printf("%d %d %d\n", i,j,k);
                    int dis = abs(j - k);
                    dp[i + 1][k] = min(dp[i + 1][k], dp[i][j] + min(dis, ringSize - dis));
                }
            }
        }
        int ans = 0x3f3f3f3f;
        for(int i = 0; i < ringSize; ++i)
            ans = min(ans, dp[keySize][i]);


        return ans + keySize;
    }
};