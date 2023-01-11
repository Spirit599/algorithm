// 二分图

class Solution {
public:
    int magnificentSets(int n, vector<vector<int>>& edges) {


        vector<int> edgess[n + 1];
        for(auto& edge : edges)
        {
            edgess[edge[0]].emplace_back(edge[1]);
            edgess[edge[1]].emplace_back(edge[0]);
        }

        int visColor[n + 1];
        vector<int> nodes;
        memset(visColor, 0, sizeof(visColor));
        function<bool(int, int)> isBipartite = [&](int color, int cur) -> bool {

            nodes.emplace_back(cur);
            visColor[cur] = color;
            for(int next : edgess[cur])
            {
                if(visColor[next] == color || (visColor[next] == 0 && !isBipartite(-color, next)))
                    return false;
            }
            return true;
        };

        bool vis[n + 1];
        function<int(int)> bfs = [&](int x) -> int {

            int depth = 0;
            memset(vis, 0, sizeof(vis));
            vis[x] = true;
            queue<int> que;
            que.emplace(x);

            while(!que.empty())
            {
                int k = que.size();
                while(k--)
                {
                    int cur = que.front();
                    que.pop();
                    for(int next : edgess[cur])
                    {
                        if(!vis[next])
                        {
                            vis[next] = true;
                            que.emplace(next);
                        }
                    }
                }
                ++depth;
            }
            return depth;
        };

        int ans = 0;
        for(int i = 1; i <= n; ++i)
        {
            if(visColor[i] != 0)
                continue;
            nodes.clear();
            int curMax = 0;
            if(!isBipartite(1, i))
                return -1;

            for(int node : nodes)
                curMax = max(curMax, bfs(node));
            ans += curMax;
        }

        return ans;
    }
};