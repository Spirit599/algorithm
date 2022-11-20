class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {

        int n = quiet.size();
        vector<int> edges[n];
        for(auto& edge : richer)
        {
            edges[edge[1]].push_back(edge[0]);
        }

        vector<int> dp(n, -1);

        function<int(int)> dfs = [&](int cur) -> int
        {
            if(dp[cur] != -1)
                return dp[cur];

            int ret = cur;
            for(int next : edges[cur])
            {
                int tmp = dfs(next);
                if(quiet[tmp] < quiet[ret])
                    ret = tmp;
            }

            return dp[cur] = ret;
        };

        for(int i = 0; i < n; ++i)
        {
            if(dp[i] == -1)
            {
                dp[i] = dfs(i);
            }
        }

        return dp;
    }
};