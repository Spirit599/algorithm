class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {

        int n = days.size();
        int maxDay = days[n - 1];
        int dp[maxDay + 1];
        memset(dp, 0, sizeof(dp));

        int idx = 0;
        for(int day = 1; day <= maxDay; ++day)
        {
            if(day != days[idx])
            {
                dp[day] = dp[day - 1];
                continue;
            }

            int x = dp[day - 1] + costs[0];
            int y = day >= 7 ? dp[day - 7] + costs[1] : costs[1];
            int z = day >= 30 ? dp[day - 30] + costs[2] : costs[2];
            dp[day] = min({x, y, z});
            ++idx;
        }
        

        return dp[maxDay];
    }
};