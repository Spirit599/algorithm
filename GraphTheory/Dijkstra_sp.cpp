typedef pair<int, int> pii;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        vector<pii> edges[n + 1];
        for(auto& edge : times)
        {
            edges[edge[0]].emplace_back(edge[1], edge[2]);
        }

        int dist[n + 1];
        memset(dist, 0x3f, sizeof(dist));
        bool vis[n + 1];
        memset(vis, 0, sizeof(vis));

        dist[k] = 0;
        for(int i = 0; i < n; ++i)
        {
            int x = -1;
            for(int j = 1; j <= n; ++j)
            {
                if(!vis[j] && (x == -1 || dist[j] < dist[x]))
                    x = j;
            }
            vis[x] = true;
            for(auto [next, cost] : edges[x])
            {
                dist[next] = min(dist[next], dist[x] + cost);
            }
        }

        bool findInf = false;
        int ans = 0;
        for(int i = 1; i <= n; ++i)
        {
            // printf("%d %d\n",i,dist[i]);
            if(dist[i] == 0x3f3f3f3f)
            {
                findInf = true;
            }
            else
            {
                ans = max(ans, dist[i]);
            }
        }

        if(!findInf)
            return ans;
        else
            return -1;
    }
};