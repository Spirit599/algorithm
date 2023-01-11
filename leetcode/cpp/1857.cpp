// 有向图检测环

class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {

        int n = colors.size();
        int vis[n];
        memset(vis, 0, sizeof(vis));
        int dp[n][26];
        memset(dp, 0, sizeof(dp));
        vector<int> edgess[n];
        for(auto& edge : edges)
            edgess[edge[0]].emplace_back(edge[1]);
        int ans = 0;


        function<bool(int)> dfs = [&](int cur) -> bool {

            if(vis[cur] == 2)
                return true;
            else if(vis[cur] == 1)
                return false;

            vis[cur] = 1;
            for(int next : edgess[cur])
            {
                if(!dfs(next))
                    return false;
                for(int i = 0; i < 26; ++i)
                    dp[cur][i] = max(dp[cur][i], dp[next][i]);
            }
            vis[cur] = 2;
            dp[cur][colors[cur] - 'a'] += 1;
            ans = max(ans, dp[cur][colors[cur] - 'a']);
            return true;
        };

        for(int i = 0; i < n; ++i)
        {
            if(!dfs(i))
                return -1;
        }

        return ans;
    }
};