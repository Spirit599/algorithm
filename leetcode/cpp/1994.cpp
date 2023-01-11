class Solution {
public:

    int numberOfGoodSubsets(vector<int>& nums) {

        int cnt[31];
        memset(cnt, 0, sizeof(cnt));
        int m = nums.size();
        for(int i = 0; i < m; ++i)
            ++cnt[nums[i]];

        const int MOD = 1e9 + 7;
        vector<int> prime({2, 3, 5, 7, 11, 13, 17, 19, 23, 29});
        int n = prime.size();
        int mask = 1 << n;
        long long dp[mask];
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;


        for(int i = 2; i <= 30; ++i)
        {
            
            int subset = 0;
            bool ok = true;
            for(int j = 0; j < n; ++j)
            {
                if(i % (prime[j] * prime[j]) == 0)
                {
                    ok = false;
                    break;
                }
                if(i % prime[j] == 0)
                {
                    subset |= (1 << j);
                }
            }
            if(!ok)
                continue;


            for(int curS = mask - 1; curS >= 1; --curS)
            {
                if((curS & subset) == subset)
                {
                    dp[curS] = (dp[curS] + dp[curS ^ subset] * cnt[i]) % MOD;
                }
            }
        }

        int ans = 0;
        for(int i = 1; i < mask; ++i)
        {
            ans = (ans + dp[i]) % MOD;
        }

        for(int i = 0; i < cnt[1]; ++i)
        {
            ans = (ans * 2) % MOD;
        }

        return ans;
    }
};