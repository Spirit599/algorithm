typedef pair<int, int> pii;

class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();
        bool vis[m][n];
        memset(vis, 0, sizeof(vis));

        int ans = -1;
        queue<pii> que;
        for(int i = 0; i < m; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                if(grid[i][j])
                {
                    vis[i][j] = true;
                    que.emplace(i, j);
                }
            }
        }

        int dires[] = {-1, 0, 1, 0, -1};
        while(!que.empty())
        {
            int k = que.size();
            while(k--)
            {
                auto [x, y] = que.front();
                que.pop();
                for(int d = 0; d < 4; ++d)
                {
                    int nx = x + dires[d];
                    int ny = y + dires[d + 1];
                    if(nx < 0 || nx >= m || ny < 0 || ny >= n || vis[nx][ny])
                        continue;
                    que.emplace(nx, ny);
                    vis[nx][ny] = true;
                }
                
            }
            ++ans;
        }

        if(ans > 0)
            return ans;
        else
            return -1;

    }
};