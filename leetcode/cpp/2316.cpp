class Solution {
public:
    vector<int> edgess[100005];
    long long countPairs(int n, vector<vector<int>>& edges) {

        for(auto& edge : edges)
        {
            edgess[edge[0]].push_back(edge[1]);
            edgess[edge[1]].push_back(edge[0]);
        }
        
        bool vis[n];
        memset(vis, 0, sizeof(vis));

        function<int(int)> dfs = [&](int cur) -> int {

            if(vis[cur])
                return 0;
            printf("cur = %d\n", cur);
            vis[cur] = true;
            int ret = 1;
            for(int next : edgess[cur])
            {
                ret += dfs(next);
            }
            return ret;
        };

        vector<int> islation;
        for(int i = 0; i < n; ++i)
        {
            int k = dfs(i);
            if(k != 0)
            {
                islation.push_back(k);
            }
        }



        int k = islation.size();
        if(k == 1)
            return 0;

        long long ans = 0;
        long long sum = islation[0];
        for(int i = 1; i < k; ++i)
        {
            ans += sum * islation[i];
            sum += islation[i];
        }

        return ans;
    }
};