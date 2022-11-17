// Bellman Ford

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {

        ++k;
        int dis[k + 1][n];
        memset(dis, 0x3f, sizeof(dis));
        dis[0][src] = 0;

        for(int i = 1; i <= k; ++i)
        {
            for(auto& edge : flights)
            {
                int from = edge[0];
                int to = edge[1];
                int cost = edge[2];
                dis[i][to] = min(dis[i][to], dis[i - 1][from] + cost);
            }
        }

        int ans = 0x3f3f3f3f;
        for(int i = 1; i <= k; ++i)
            ans = min(ans, dis[i][dst]);

        return ans != 0x3f3f3f3f ? ans : -1;
    }
};