class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {

        int maxDay = 400;
        int dp[maxDay];
        memset(dp, 0x3f, sizeof(dp));

        int day = days[0];
        dp[day] = costs[0];
        dp[day + 6] = costs[1];
        dp[day + 29] = costs[2];

        int n = days.size();
        for(int i = 1; i < n; ++i)
        {
            int pre = days[i - 1];
            int day = days[i];
            int minn = 0x3f3f3f3f;
            for(int j = pre; j < day; ++j)
                minn = min(minn, dp[j]);

            // printf("%d %d %d\n", pre,day,minn);

            dp[day] = min(dp[day], minn + costs[0]);
            dp[day + 6] = min(dp[day + 6], minn + costs[1]);
            dp[day + 29] = min(dp[day + 29], minn + costs[2]);
        }

        // for(int i = 0; i < days[n - 1] + 31; ++i)
        //     printf("%d %d\n", i, dp[i]);

        int minn = 0x3f3f3f3f;
        for(int i = days[n - 1]; i < days[n - 1] + 31; ++i)
            minn = min(minn, dp[i]);

        return minn;
    }
};