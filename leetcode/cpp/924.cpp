class Solution {
public:
    int minMalwareSpread(vector<vector<int>>& graph, vector<int>& initial) {

        int n = graph.size();
        bool black[305];
        memset(black, 0, sizeof(black));
        sort(initial.begin(), initial.end());
        for(int num : initial)
            black[num] = true;

        int ans = initial[0];
        int maxx = -1;

        bool vis[n];
        memset(vis, 0, sizeof(vis));

        function<pair<int, int>(int)> dfs = [&](int cur) -> pair<int, int> {

            pair<int, int> ret = make_pair(0, 0);
            if(vis[cur])
                return ret;
            vis[cur] = true;
            if(black[cur])
                ++ret.second;
            else
                ++ret.first;

            for(int next = 0; next < n; ++next)
            {
                if(graph[cur][next] == 1)
                {
                    auto [w, b] = dfs(next);
                    ret.first += w;
                    ret.second += b;
                }
            }
            return ret;
        };

        for(int num : initial)
        {
            if(vis[num])
                continue;
            auto [w, b] = dfs(num);
            if(b > 1)
                continue;
            if(w > maxx)
            {
                maxx = w;
                ans = num;
            }
        }

        return ans;
    }
};