typedef pair<int, int> pii;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        vector<pii> edges[n + 1];
        for(auto& edge : times)
        {
            edges[edge[0]].emplace_back(edge[1], edge[2]);
        }
        
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        int dist[n + 1];
        memset(dist, 0x3f, sizeof(dist));

        pq.emplace(0, k);
        int ans = 0;

        while(!pq.empty())
        {
            auto [curDist, curNode] = pq.top();
            pq.pop();

            if(dist[curNode] < curDist)
                continue;
            dist[curNode] = curDist;
            ans = max(ans, curDist);
            for(auto [next, cost] : edges[curNode])
            {
                if(curDist + cost < dist[next])
                {
                    dist[next] = curDist + cost;
                    pq.emplace(curDist + cost, next);
                }
            }
        }

        bool findInf = false;
        for(int i = 1; i <= n; ++i)
        {
            // printf("%d %d\n",i,dist[i]);
            if(dist[i] == 0x3f3f3f3f)
            {
                findInf = true;
                break;
            }
        }

        if(!findInf)
            return ans;
        else
            return -1;
    }
};