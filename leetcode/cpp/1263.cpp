struct boxInfo
{
    int bx;
    int by;
    int sx;
    int sy;
};

class Solution {
public:
    int minPushBox(vector<vector<char>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        int bx = -1;
        int by = -1;
        int sx = -1;
        int sy = -1;
        int tx = -1;
        int ty = -1;
        for(int i = 0; i < m; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                if(grid[i][j] == 'B')
                {
                    grid[i][j] = '.';
                    bx = i;
                    by = j;
                }
                else if(grid[i][j] == 'S')
                {
                    grid[i][j] = '.';
                    sx = i;
                    sy = j;
                }
                else if(grid[i][j] == 'T')
                {
                    grid[i][j] = '.';
                    tx = i;
                    ty = j;
                }
            }
        }

        bool visGrid[m][n];

        bool vis[m][n][m][n];
        memset(vis, 0, sizeof(vis));
        vis[bx][by][sx][sy] = true;
        queue<boxInfo> que;
        que.push({bx, by, sx, sy});
        int depth = 0;

        auto isEmptySpace = [&](int i, int j) -> bool {

            if(i >= 0 && i < m && j >= 0 && j < n && grid[i][j] == '.')
                return true;
            return false;
        };

        function<bool(int, int, int, int)> canGet = [&](int tx, int ty, int cx, int cy) -> bool {

            if(cx < 0 || cx >= m || cy < 0 || cy >= n || grid[cx][cy] == '#' || (cx == bx && cy == by) || visGrid[cx][cy])
                return false;
            if(cx == tx && cy == ty)
                return true;
            bool ret = false;
            visGrid[cx][cy] = true;
            ret |= canGet(tx, ty, cx + 1, cy);
            ret |= canGet(tx, ty, cx - 1, cy);
            ret |= canGet(tx, ty, cx, cy + 1);
            ret |= canGet(tx, ty, cx, cy - 1);
            return ret;
        };

        while(!que.empty())
        {
            int k = que.size();
            while(k--)
            {
                auto binfo = que.front();
                que.pop();
                bx = binfo.bx;
                by = binfo.by;
                sx = binfo.sx;
                sy = binfo.sy;
                // printf("%d %d %d %d\n", bx,by,sx,sy);
                if(bx == tx && by == ty)
                    return depth;

                if(isEmptySpace(bx + 1, by) && isEmptySpace(bx - 1, by))
                {
                    memset(visGrid, 0, sizeof(visGrid));
                    if(!vis[bx - 1][by][bx][by] && canGet(bx + 1, by, sx, sy))
                    {
                        vis[bx - 1][by][bx][by] = true;
                        que.push({bx - 1, by, bx, by});
                    }
                    memset(visGrid, 0, sizeof(visGrid));
                    if(!vis[bx + 1][by][bx][by] && canGet(bx - 1, by, sx, sy))
                    {
                        vis[bx + 1][by][bx][by] = true;
                        que.push({bx + 1, by, bx, by});
                    }
                }
                if(isEmptySpace(bx, by + 1) && isEmptySpace(bx, by - 1))
                {
                    memset(visGrid, 0, sizeof(visGrid));
                    if(!vis[bx][by - 1][bx][by] && canGet(bx, by + 1, sx, sy))
                    {
                        vis[bx][by - 1][bx][by] = true;
                        que.push({bx, by - 1, bx, by});
                    }
                    memset(visGrid, 0, sizeof(visGrid));
                    if(!vis[bx][by + 1][bx][by] && canGet(bx, by - 1, sx, sy))
                    {
                        vis[bx][by + 1][bx][by] = true;
                        que.push({bx, by + 1, bx, by});
                    }
                }
            }
            // printf("\n");
            ++depth;
        }

        return -1;
    }
};