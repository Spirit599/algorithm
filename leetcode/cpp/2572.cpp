class Solution {
public:
    int squareFreeSubsets(vector<int>& nums) {
        
        const int maxn = 10;
        int prime[10] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};

        auto check = [&](int num) -> bool {
            for(int i = 0; i < maxn; ++i)
                if(num % (prime[i] * prime[i]) == 0)
                    return true;
            return false;
        };
        const int mod = 1e9 + 7;
        int S = 1 << maxn;
        int dp[S];
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;

        for(int num : nums)
        {
            if(check(num))
                continue;
            int mask = 0;
            for(int i = 0; i < maxn; ++i)
            {
                if(num % prime[i] == 0)
                    mask |= 1 << i;
            }
            for(int subset = S - 1; subset >= 0; --subset)
            {
                if((subset & mask) == 0)
                {
                    dp[subset | mask] = (dp[subset | mask] + dp[subset]) % mod;
                }
            }
        }

        int ans = 0;
        for(int i = 0; i < S; ++i)
            ans = (ans + dp[i]) % mod;
        return  (ans - 1 + mod) % mod;
    }
};