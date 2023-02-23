class Solution {
public:
    int stoneGameII(vector<int>& piles) {

        int n = piles.size();
        int dp[n][n + 2];
        memset(dp, 0xc0, sizeof(dp));
        int finf = 0xc0c0c0c0;

        function<int(int, int)> dfs = [&](int idx, int m) -> int {

            // printf("%d %d\n", idx, m);
            if(dp[idx][m] != finf)
                return dp[idx][m];

            int ret = finf;
            int cur = 0;
            int remain = n - idx;
            // printf("%d remain = %d\n", m, remain);
            if(m >= remain)
            {
                for(int i = idx; i < n; ++i)
                    cur += piles[i];
                ret = max(ret, cur);
            }
            else
            {
                for(int i = idx; i < n; ++i)
                {
                    int cnt = i - idx + 1;
                    if(cnt > m)
                        break;
                    cur += piles[i];
                    ret = max(ret, cur - dfs(i + 1, max(m, min(2 * cnt, n))));
                }
            }

            // printf("%d %d %d\n", idx, m, ret);
            return dp[idx][m] = ret;
        };

        int k = dfs(0, 2);
        int all = accumulate(piles.begin(), piles.end(), 0);
        return (all - k) / 2 + k;
    }
};