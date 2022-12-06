class Solution {
public:
    int minCost(int maxn, vector<int>& cuts) {

        cuts.emplace_back(0);
        cuts.emplace_back(maxn);
        sort(cuts.begin(), cuts.end());
        int n = cuts.size();

        int dp[n][n];
        memset(dp, 0x3f, sizeof(dp));

        for(int i = 0; i < n - 1; ++i)
        {
            dp[i][i + 1] = 0;
        }

        for(int len = 3; len <= n; ++len)
        {
            for(int start = 0; start + len - 1 < n; ++start)
            {
                int end = start + len - 1;

                for(int split = start + 1; split < end; ++split)
                    dp[start][end] = min(dp[start][end], dp[start][split] + dp[split][end]);
                dp[start][end] += cuts[end] - cuts[start];
            }
        }

        return dp[0][n - 1];
    }
};