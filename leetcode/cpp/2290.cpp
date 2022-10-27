class Solution {
public:
    struct cood
    {
        int i;
        int j;
    };
    int minimumObstacles(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<bool>> vis(m, vector<bool>(n));
        queue<cood> que;

        int dires[] = {-1, 0, 1, 0, -1};

        function<void(int, int)> dfs = [&](int i, int j) -> void {
            if(i < 0 || i >= m || j < 0 || j >= n || vis[i][j] || grid[i][j])
                return ;
            que.push({i, j});
            vis[i][j] = true;
            dfs(i + 1, j);
            dfs(i - 1, j);
            dfs(i, j + 1);
            dfs(i, j - 1);
        };

        dfs(0, 0);
        int ans = 0;
        while(!que.empty())
        {
            int k = que.size();
            while(k--)
            {
                cood cur = que.front();
                if(cur.i == m - 1 && cur.j == n - 1)
                    return ans;
                que.pop();
                for(int d = 0; d < 4; ++d)
                {
                    int i = cur.i + dires[d];
                    int j = cur.j + dires[d + 1];
                    if(i < 0 || i >= m || j < 0 || j >= n || vis[i][j])
                        continue;

                    grid[i][j] = 0;
                    dfs(i, j);
                }
            }
            ++ans;
        }

        return -1;
    }
};