typedef pair<int, int> pii;

class Solution {
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        
        vector<pii> dp;

        int m = grid.size();
        int n = grid[0].size();
        bool vis[m][n];
        memset(vis, 0, sizeof(vis));

        auto cmp = [&](const pii& p1, const pii& p2) {
            return grid[p1.first][p1.second] > grid[p2.first][p2.second];
        };


        priority_queue<pii, vector<pii>, decltype(cmp)> pq(cmp);
        int pre = grid[0][0];
        pq.emplace(0, 0);
        vis[0][0] = true;
        int cur = 0;
        int dires[] = {-1, 0, 1, 0, -1};
        int maxGrid = pre;

        while(!pq.empty())
        {
            auto [x, y] = pq.top();
            pq.pop();
            // printf("x = %d y = %d grid[x][y] = %d\n",x,y,grid[x][y]);
            if(grid[x][y] > pre)
            {
                
                dp.emplace_back(pre + 1, cur);
                // printf("%d %d\n", pre + 1, cur);
                pre = grid[x][y];

            }
            ++cur;

            for(int d = 0; d < 4; ++d)
            {
                int i = x + dires[d];
                int j = y + dires[d + 1];
                if(i >= m || i < 0 || j >= n || j < 0 || vis[i][j])
                    continue;
                vis[i][j] = true;
                pq.emplace(i, j);
            }
        }
        dp.emplace_back(pre + 1, cur);
        

        int querySize = queries.size();
        vector<int> ans(querySize);
        int inf = 0x3f3f3f3f;
        for(int i = 0; i < querySize; ++i)
        {
            auto it = lower_bound(dp.begin(), dp.end(), make_pair(queries[i], inf));
            if(it != dp.begin())
                ans[i] = (--it)->second;
            else
                ans[i] = 0;
        }


        return ans;

    }
};