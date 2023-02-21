class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {

        vector<int> edges[n + 1];
        for(auto& edge : dislikes)
        {
            edges[edge[0]].emplace_back(edge[1]);
            edges[edge[1]].emplace_back(edge[0]);
        }

        int visColor[n + 1];
        memset(visColor, 0, sizeof(visColor));

        function<bool(int, int)> isBipartite = [&](int cur, int color) -> bool {
            
            visColor[cur] = color;
            for(int next : edges[cur])
            {
                if(visColor[next] == color || (visColor[next] == 0 && !isBipartite(next, -color)))
                    return false;
            }
            return true;
        };

        for(int i = 1; i <= n; ++i)
        {
            if(visColor[i] != 0)
                continue;
            if(!isBipartite(i, 1))
                return false;
        }
        return true;
    }
};