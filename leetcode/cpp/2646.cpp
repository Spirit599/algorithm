class Solution {
public:
    int minimumTotalPrice(int n, vector<vector<int>>& edges, vector<int>& price, vector<vector<int>>& trips) {
        
        int cnt[n];
        memset(cnt, 0, sizeof(cnt));
        vector<int> edgess[n];
        for(auto& edge : edges)
        {
            edgess[edge[0]].emplace_back(edge[1]);
            edgess[edge[1]].emplace_back(edge[0]);
        }

        for(auto& t : trips)
        {
            int end = t[1];
            function<bool(int, int)> dfs = [&](int fa, int cur) -> bool {

                if(cur == end)
                {
                    ++cnt[end];
                    return true;
                }

                for(int next : edgess[cur])
                {
                    if(next != fa && dfs(cur, next))
                    {
                        ++cnt[cur];
                        return true;
                    }
                }
                return false;
            };
            dfs(-1, t[0]);
        }

        for(int i = 0; i < n; ++i)
            printf("%d\n", cnt[i]);

        typedef pair<int, int> pii;

        function<pii(int, int)> dfs = [&](int fa, int cur) -> pii {

            int nh = cnt[cur] * price[cur];
            int h = nh / 2;

            for(int next : edgess[cur])
            {
                if(next != fa)
                {
                    pii ret = dfs(cur, next);
                    nh += min(ret.first, ret.second);
                    h += ret.first;
                }
            }

            return make_pair(nh, h);
        };

        auto [nh, h] = dfs(-1, 0);

        return min(nh, h);
    }
};