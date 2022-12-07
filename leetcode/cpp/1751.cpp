class Solution {
public:
    int maxValue(vector<vector<int>>& events, int k) {

        int n = events.size();
        int dp[n + 1][k + 1];
        memset(dp, 0, sizeof(dp));

        sort(events.begin(), events.end(), [](const vector<int>& v1, const vector<int>& v2) {return v1[1] < v2[1];});
        vector<int> endTime;

        for(int i = 1; i <= n; ++i)
        {
            auto it = lower_bound(endTime.begin(), endTime.end(), events[i - 1][0]);
            int pre = it - endTime.begin();
            for(int j = 1; j <= k; ++j)
            {
                dp[i][j] = max(dp[i - 1][j], dp[pre][j - 1] + events[i - 1][2]);
            }
            endTime.emplace_back(events[i - 1][1]);
        }

        return dp[n][k];

    }
};