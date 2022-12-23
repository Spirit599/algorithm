class Solution {
public:
    int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& passingFees) {

        int n = passingFees.size();
        int dp[maxTime + 1][n];
        memset(dp, 0x3f, sizeof(dp));
        int inf = 0x3f3f3f3f;

        vector<pair<int, int>> edgess[n];
        for(auto& edge : edges)
        {
            edgess[edge[0]].emplace_back(edge[1], edge[2]);
            edgess[edge[1]].emplace_back(edge[0], edge[2]);
        }

        dp[0][0] = passingFees[0];
        for(int time = 1; time <= maxTime; ++time)
        {
            for(int node = 0; node < n; ++node)
            {
                dp[time][node] = dp[time - 1][node];
                for(auto& pii : edgess[node])
                {
                    auto [next, addTime] = pii;
                    if(addTime <= time)
                    {
                        dp[time][node] = min(dp[time][node], dp[time - addTime][next] + passingFees[node]);
                    }
                }
            }
        }

        if(dp[maxTime][n - 1] != inf)
            return dp[maxTime][n - 1];
        else
            return -1;

    }
};