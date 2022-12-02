typedef pair<int, int> pii;

class Solution {
public:
    int reachableNodes(vector<vector<int>>& edges, int maxMoves, int n) {

        int dis[n];
        memset(dis, -1, sizeof(dis));

        vector<pii> edgess[n];
        for(auto& edge : edges)
        {
            edgess[edge[0]].emplace_back(edge[1], edge[2] + 1);
            edgess[edge[1]].emplace_back(edge[0], edge[2] + 1);
        }

        priority_queue<pii> pq;
        dis[0] = maxMoves;
        pq.emplace(maxMoves, 0);

        while(!pq.empty())
        {
            int cur = pq.top().second;
            int moves = pq.top().first;
            pq.pop();

            if(dis[cur] > moves)
                continue;

            for(auto& next : edgess[cur])
            {
                int allMove = moves - next.second;
                int nextNode = next.first;
                if(dis[nextNode] < allMove)
                {
                    pq.emplace(allMove, nextNode);
                    dis[nextNode] = allMove;
                }
            }
        }

        int ans = 0;
        for(int i = 0; i < n; ++i)
        {
            if(dis[i] >= 0)
                ++ans;
        }

        
        for(auto& edge : edges)
        {
            ans += min(max(dis[edge[0]], 0) + max(dis[edge[1]], 0), edge[2]);
        }

        return ans;
    }
};