const int mod = 1000000007;

class Solution {
public:
    int numberOfWays(int startPos, int endPos, int k) {
        

        
        int dif = abs(startPos - endPos);

        int plus = k - dif;
        if(plus < 0 || plus % 2 == 1)
            return 0;

        int low = plus / 2;

        cout<<k<<" "<<low<<endl;

        return com(k, low);
    }

    int com(int n, int m)
    {
        long long dp[n + 1][m + 1];
        memset(dp, 0, sizeof(dp));
        for(int i = 0; i <= n; ++i)
            dp[i][0] = 1;


        for(int i = 1; i <= n; ++i)
        {
            for(int j = 1; j <= m; ++j)
            {
                dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - 1]) % mod;
            }
        }

        return dp[n][m];
    }
};