const int MOD = 1000000007;

class Solution {
public:
    int gcd(int n, int m) {
        while(n != 0) {
            int r = m % n;
            m = n;
            n = r;
        }
        return m;
    }
    int distinctSequences(int n) {
        
        int dp[n][8][8];
        memset(dp, -1, sizeof(dp));
        bool gcdIs1[8][8];
        memset(gcdIs1, 0, sizeof(gcdIs1));

        for(int i = 1; i <= 7; ++i)
        {
            for(int j = i + 1; j <= 7; ++j)
            {
                if(gcd(i, j) == 1)
                {
                    gcdIs1[i][j] = true;
                    gcdIs1[j][i] = true;
                }
            }
        }


        function<int(int, int, int)> dfs = [&](int depth, int pre, int prepre) -> int {

            if(depth == n)
                return 1;
            if(dp[depth][pre][prepre] != -1)
                return dp[depth][pre][prepre];

            int ret = 0;
            for(int i = 1; i <= 6; ++i) 
            {
                if(gcdIs1[i][pre] && i != pre && i != prepre)
                {
                    ret = (ret + dfs(depth + 1, i, pre)) % MOD;
                }
            }

            dp[depth][pre][prepre] = ret;
            return ret;

        };

        return dfs(0, 7, 7);
    }
};