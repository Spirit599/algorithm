typedef pair<int, int> pii;
typedef pair<long long, int> plli;
class Solution {
public:
    vector<long long> dijkstra(int n, vector<pii> edges[], int src) {

        priority_queue<plli, vector<plli>, greater<plli>> pq;
        vector<long long> dis(n, LONG_MAX / 3);

        pq.emplace(0, src);

        while(!pq.empty())
        {
            auto [cost, cur] = pq.top();
            pq.pop();

            if(dis[cur] < cost)
                continue;
            dis[cur] = cost;

            for(auto [next, ncost] : edges[cur])
            {

                if(dis[next] > cost + ncost)
                {
                    dis[next] = cost + ncost;
                    pq.emplace(dis[next], next);
                }
            }
        }

        return dis;
    }
    long long minimumWeight(int n, vector<vector<int>>& edges, int src1, int src2, int dest) {
        
        vector<pii> edgess[n];
        vector<pii> preEdgess[n];
        for(auto& edge : edges)
        {
            edgess[edge[0]].emplace_back(edge[1], edge[2]);
            preEdgess[edge[1]].emplace_back(edge[0], edge[2]);
        }

        auto d1 = dijkstra(n, edgess, src1);
        auto d2 = dijkstra(n, edgess, src2);
        auto d3 = dijkstra(n, preEdgess, dest);

        long long ans = LONG_MAX;
        for(int i = 0; i < n; ++i)
        {
            ans = min(ans, d1[i] + d2[i] + d3[i]);
        }

        if(ans < LONG_MAX / 3)
            return ans;
        else
            return -1;
    }
};