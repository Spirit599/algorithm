class Solution {
public:
    vector<int> countSubgraphsForEachDiameter(int n, vector<vector<int>>& edges) {

        vector<int> ans(n - 1);
        vector<int> edgess[n + 1];
        for(auto& edge : edges)
        {
            edgess[edge[0]].emplace_back(edge[1]);
            edgess[edge[1]].emplace_back(edge[0]);
        }

        bool isVaild[n + 1];
        bool vis[n + 1];

        function<pair<int, int>(int, int)> dfs = [&](int cur, int fa) -> pair<int, int> {

            int farNode = cur;
            int maxLen = 0;

            for(int next : edgess[cur])
            {
                if(isVaild[next] && next != fa)
                {
                    vis[next] = true;
                    auto [f, l] = dfs(next, cur);
                    if(l > maxLen)
                    {
                        maxLen = l;
                        farNode = f;
                    }
                }
            }

            return make_pair(farNode, maxLen + 1);
        };

        auto getMaxLen = [&](vector<int>& nodes) -> int {

            memset(isVaild, 0, sizeof(isVaild));
            memset(vis, 0, sizeof(vis));
            for(int node : nodes)
            {
                isVaild[node] = true;
            }

            vis[nodes[0]] = true;
            auto [farNode, maxLen] = dfs(nodes[0], -1);


            for(int node : nodes)
                if(!vis[node])
                    return -1;

            auto [fNode, ans] = dfs(farNode, -1);
            return ans - 1;
        };

        int S = 1 << n;
        for(int mask = 1; mask < S; ++mask)
        {
            if(__builtin_popcount(mask) == 1)
                continue;
            vector<int> node;
            for(int i = 0; i < n; ++i)
            {
                if(mask & (1 << i))
                {
                    node.emplace_back(i + 1);
                }
            }
            int len = getMaxLen(node);
            if(len == -1)
                continue;
            
            ++ans[len - 1];
        }

        return ans;
    }
};