class Solution {
public:
    int numOfWays(int n) {

        long long dp1 = 6;
        long long dp2 = 6;
        int MOD = 1e9 + 7;

        for(int i = 1; i < n; ++i)
        {
            long long ndp1 = 2 * dp1 + 2 * dp2;
            long long ndp2 = 2 * dp1 + 3 * dp2;
            dp1 = ndp1 % MOD;
            dp2 = ndp2 % MOD;
        }

        return (dp1 + dp2) % MOD;
    }
};