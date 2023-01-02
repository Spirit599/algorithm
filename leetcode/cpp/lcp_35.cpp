typedef tuple<int, int, int> tiii;
typedef pair<int, int> pii;
class Solution {
public:
    int electricCarPlan(vector<vector<int>>& paths, int cnt, int start, int end, vector<int>& charge) {

        int n = charge.size();
        vector<pii> edges[n];
        for(auto edge : paths)
        {
            int x = edge[0];
            int y = edge[1];
            int cost = edge[2];
            edges[x].emplace_back(y, cost);
            edges[y].emplace_back(x, cost);
        }

        
        int t[n][cnt + 1];
        memset(t, 0x3f, sizeof(t));

        priority_queue<tiii, vector<tiii>, greater<>> pq;
        pq.emplace(0, 0, start);
        t[start][0] = 0;


        while(!pq.empty())
        {
            auto [time, ele, cur] = pq.top();
            pq.pop();

            if(time > t[cur][ele])
                continue;
            if(cur == end)
                return time;

            if(ele != cnt)
            {
                int ntime = time + charge[cur];
                if(ntime < t[cur][ele + 1])
                {
                    t[cur][ele + 1] = ntime;
                    pq.emplace(ntime, ele + 1, cur);
                }
            }

            for(auto [next, cost] : edges[cur])
            {
                int ntime = time + cost;
                if(ele >= cost && ntime < t[next][ele - cost])
                {
                    t[next][ele - cost] = ntime;
                    pq.emplace(ntime, ele - cost, next);
                }
            }
        }


        return t[end][0];
    }
};