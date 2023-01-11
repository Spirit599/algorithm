class Solution {
public:
    bool canDistribute(vector<int>& nums, vector<int>& quantity) {

        unordered_map<int, int> memo;
        for(int num : nums)
            ++memo[num];
        vector<int> cnt;
        for(auto& kv : memo)
            cnt.emplace_back(kv.second);

        int n = cnt.size();
        int m = quantity.size();
        int S = 1 << m;


        int sum[S];
        memset(sum, 0, sizeof(sum));
        for(int mask = 1; mask < S; ++mask)
        {
            for(int j = 0; j < m; ++j)
            {
                if(mask & (1 << j))
                {
                    sum[mask] = sum[mask ^ (1 << j)] + quantity[j];
                    break;
                }
            }
        }

        bool dp[n + 1][S];
        memset(dp, 0, sizeof(dp));
        dp[0][0] = true;

        for(int i = 0; i < n; ++i)
        {
            for(int mask = 0; mask < S; ++mask)
            {
                if(dp[i][mask])
                {
                    dp[i + 1][mask] = true;
                    continue;
                }
                for(int subset = mask; subset != 0; subset = (subset - 1) & mask)
                {
                    int preSubset = mask ^ subset;
                    if(dp[i][preSubset] && cnt[i] >= sum[subset])
                    {
                        dp[i + 1][mask] = true;
                        break;
                    }
                }
            }
        }

        return dp[n][S - 1];

    }
};