class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {

        int n = graph.size();
        int S = (1 << n);
        int dp[n][S];
        int inf = 0x3f3f3f3f;
        int ans = inf;
        bool vis[n];
        queue<int> que;

        for(int source = 0; source < n; ++source)
        {
            memset(dp, 0x3f, sizeof(dp));
            dp[source][1 << source] = 0;
            int startS = 1 >> source;
            for(int curS = startS; curS < S; ++curS)
            {
                
                while(!que.empty())
                    que.pop();
                memset(vis, 0, sizeof(vis));
                for(int i = 0; i < n; ++i)
                    if(dp[i][curS] != inf)
                        que.emplace(i);

                while(!que.empty())
                {
                    int i = que.front();
                    que.pop();
                    for(int next : graph[i])
                    {
                        dp[next][curS | (1 << next)] = min(dp[next][curS | (1 << next)], dp[i][curS] + 1);
                        if(dp[next][curS | (1 << next)] != inf && !vis[next])
                        {
                            vis[next] = true;
                            que.emplace(next);
                        }
                    }
                }
            }

            for(int i = 0; i < n; ++i)
            {
                ans = min(ans, dp[i][S - 1]);
            }
        }

        return ans;
    }
};