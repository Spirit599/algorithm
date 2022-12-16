typedef pair<int, int> pii;

class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        
        vector<int> edgess[n + 1];
        for(auto& edge : edges)
        {
            edgess[edge[0]].emplace_back(edge[1]);
            edgess[edge[1]].emplace_back(edge[0]);
        }

        int cost1[n + 1];
        memset(cost1, -1, sizeof(cost1));
        int cost2[n + 1];
        memset(cost2, -1, sizeof(cost2));

        auto getVitalTime = [&](int time) -> int {

            int k = time / change;
            if(k & 1)
                return (k + 1) * change;
            else
                return time;
        };

        queue<pii> que;
        que.emplace(0, 1);

        while(!que.empty())
        {
            auto [cost, cur] = que.front();
            que.pop();

            if(cost1[cur] == -1)
                cost1[cur] = cost;
            else if(cost1[cur] == cost)
                continue;
            else if(cost2[cur] == -1)
                cost2[cur] = cost;
            else
                continue;

            cost = getVitalTime(cost);
            for(int next : edgess[cur])
            {
                int newCost = cost + time;
                if(newCost == cost1[next] || cost2[next] != -1)
                    continue;
                que.emplace(newCost, next);
            }
        }

        return cost2[n];
    }
};