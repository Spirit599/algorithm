class Solution {
public:
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {

        vector<int> edgess[n + 1];
        bool vis[n + 1];
        memset(vis, 0, sizeof(vis));
        for(auto& edge : edges)
        {
            edgess[edge[0]].emplace_back(edge[1]);
            edgess[edge[1]].emplace_back(edge[0]);
        }

        queue<pair<int, double>> que;
        que.emplace(1, 1);
        vis[1] = true;
        ++t;

        while(t--)
        {
            int num = que.size();
            while(num--)
            {
                int cur = que.front().first;
                double p = que.front().second;
                que.pop();
                int k = edgess[cur].size();
                if(cur != 1)
                    --k;
                if(cur == target)
                {
                    if(k == 0 || t == 0)
                        return p;
                    else
                        return 0;
                }
                
                for(int next : edgess[cur])
                {
                    if(!vis[next])
                    {
                        vis[next] = true;
                        double pNext = p / k;
                        que.emplace(next, pNext);
                    }
                }
            }
        }


        return 0;
    }
};