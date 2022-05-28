class Solution {
public:
    void dfs(vector<vector<int>>& grid, bool visit[][100],
            int i, int j, queue<pair<int, int>>& que)
    {


        //cout<<i<<j<<endl;

        if(i == m - 1 && j == n - 1)
        {
            return ;
        }
        
        if(grid[i][j] == 1)
        {   
            if(j + 1 < n && !visit[i][j + 1])
            {
                que.push({i, j + 1});
                visit[i][j + 1] = true;
                dfs(grid, visit, i, j + 1, que);
                //visit[i][j + 1] = false;
            }
        }
        else if(grid[i][j] == 2)
        {
            if(j - 1 >= 0 && !visit[i][j - 1])
            {
                que.push({i, j - 1});
                visit[i][j - 1] = true;
                dfs(grid, visit, i, j - 1, que);
                //visit[i][j - 1] = false;
            }
        }
        else if(grid[i][j] == 3)
        {
            if(i + 1 < m && !visit[i + 1][j])
            {
                que.push({i + 1, j});
                visit[i + 1][j] = true;
                dfs(grid, visit, i + 1, j, que);
                //visit[i + 1][j] = false;
            }
        }
        else
        {

            if(i - 1 >= 0 && !visit[i - 1][j])
            {
                que.push({i - 1, j});
                visit[i - 1][j] = true;
                dfs(grid, visit, i - 1, j, que);
                //visit[i - 1][j] = false;
            }
        }

    }
    int minCost(vector<vector<int>>& grid) {

        m = grid.size();
        n = grid[0].size();
        bool visit[100][100];

        memset(visit, 0, sizeof(visit));

        queue<pair<int, int>> que;
        que.push({0, 0});
        visit[0][0] = true;

        dfs(grid, visit, 0, 0, que);
        if(visit[m - 1][n - 1])
            return 0;

        int level_num = que.size();
        int level = 1;
        int num = 0;

        while(!que.empty())
        {
            auto i = que.front();

            if(i.first + 1 < m && !visit[i.first + 1][i.second])
            {
                que.push({i.first + 1, i.second});
                visit[i.first + 1][i.second] = true;
                dfs(grid, visit, i.first + 1, i.second, que);
            }

            if(i.first - 1 >= 0 && !visit[i.first - 1][i.second])
            {
                que.push({i.first - 1, i.second});
                visit[i.first - 1][i.second] = true;
                dfs(grid, visit, i.first - 1, i.second, que);
            }

            if(i.second + 1 < n && !visit[i.first][i.second + 1])
            {
                que.push({i.first, i.second + 1});
                visit[i.first][i.second + 1] = true;
                dfs(grid, visit, i.first, i.second + 1, que);
            }

            if(i.second - 1 >= 0 && !visit[i.first][i.second - 1])
            {
                que.push({i.first, i.second - 1});
                visit[i.first][i.second - 1] = true;
                dfs(grid, visit, i.first, i.second - 1, que);
            }

            que.pop();

            if(visit[m - 1][n - 1])
                return level;

            ++num;
            if(num == level_num)
            {
                level_num = que.size();
                num = 0;
                ++level;
                //cout<<endl;
            }
        }

        return 0;
    }
private:
    int m;
    int n;
};