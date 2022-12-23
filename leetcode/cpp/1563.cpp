class Solution {
public:
    int stoneGameV(vector<int>& stoneValue) {

        int n = stoneValue.size();
        int pre[n + 1];
        pre[0] = 0;
        for(int i = 0; i < n; ++i)
            pre[i + 1] = stoneValue[i] + pre[i];

        int dp[n][n];
        memset(dp, -1, sizeof(dp));


        function<int(int, int)> dfs = [&](int ll, int rr) -> int {

            // printf("%d %d\n", ll,rr);

            if(ll == rr)
                return 0;
            else if(ll + 1 == rr)
                return min(stoneValue[ll], stoneValue[rr]);

            if(dp[ll][rr] != -1)
                return dp[ll][rr];

            int sum = pre[rr + 1] - pre[ll];
            int lsum = 0;
            int rsum = sum;
            int ret = 0;
            for(int i = ll; i < rr; ++i)
            {
                lsum += stoneValue[i];
                rsum -= stoneValue[i];
                if(lsum < rsum)
                {
                    ret = max(ret, dfs(ll, i) + lsum);
                }
                else if(lsum > rsum)
                {
                    ret = max(ret, dfs(i + 1, rr) + rsum);
                }
                else
                {
                    ret = max({ret, dfs(ll, i) + lsum, dfs(i + 1, rr) + rsum});
                }

            }


            return dp[ll][rr] = ret;
        };

        return dfs(0, n - 1);
    }
};