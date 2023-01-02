class Solution {
public:
    int mod = 1e9 + 7;
    int idealArrays(int n, int maxValue) {
        
        int k = 20;
        int comb[n + k][k];
        memset(comb, 0, sizeof(comb));
        comb[0][0] = 1;

        for(int i = 1; i < n + k; ++i)
        {
            comb[i][0] = 1;
            for(int j = 1; j < min(k, i + 1); ++j)
            {
                comb[i][j] = (comb[i - 1][j - 1] + comb[i - 1][j]) % mod;
            }
        }

        vector<int> baseCnt[maxValue + 1];
        for(int num = 1; num <= maxValue; ++num)
        {
            int numc = num;
            for(int i = 2; i * i <= numc; ++i)
            {
                if(numc % i == 0)
                {
                    int cnt = 0;
                    while(numc % i == 0)
                    {
                        numc = numc / i;
                        ++cnt;
                    }
                    baseCnt[num].emplace_back(cnt);
                }
            }
            if(numc != 1)
                baseCnt[num].emplace_back(1);
        }

        long long ans = 0;

        for(int num = 1; num <= maxValue; ++num)
        {
            long long cur = 1;
            for(int cnt : baseCnt[num])
            {
                cur = cur * comb[n + cnt - 1][cnt];
                cur %= mod;
            }
            ans += cur;
            ans %= mod;
        }

        return ans;

    }
};