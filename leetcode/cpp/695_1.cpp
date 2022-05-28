const int MAX_MN = 50;
//dfs 
class Solution {
private:
    int ans = 0;
    int cnt = 0;
    int m;
    int n;
public:
    void dfs(bool visit[MAX_MN][MAX_MN], vector<vector<int>>& grid, int ci, int cj)
    {
        int dires[] = {-1, 0, 1, 0, -1};
        for (int k = 0; k < 4; ++k)
        {
            int i = ci + dires[k];
            int j = cj + dires[k + 1];
            if(i >= 0 && i < m && j >= 0 && j < n && grid[i][j] && !visit[i][j])
            {
                visit[i][j] = true;
                ++cnt;
                dfs(visit, grid, i, j);
            } 
        }
        ans = max(ans, cnt);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {

        m = grid.size();
        n = grid[0].size();

        bool visit[MAX_MN][MAX_MN];
        memset(visit, 0, sizeof(visit));

        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if(grid[i][j] && !visit[i][j])
                {
                    visit[i][j] = true;
                    cnt = 1;
                    dfs(visit, grid, i, j);
                }
            }
        }

        return ans;
    }
};