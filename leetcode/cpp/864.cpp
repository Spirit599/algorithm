struct nodeInfo
{
    int x;
    int y;
    int keysInfo;
};
class Solution {
public:
    int shortestPathAllKeys(vector<string>& grid) {

        
        int m = grid.size();
        int n = grid[0].size();
        int targetStatus = 0;
        int si;
        int sj;
        for(int i = 0; i < m; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                if(grid[i][j] >= 'a' && grid[i][j] <= 'f')
                    targetStatus |= 1 << (grid[i][j] - 'a');
                if(grid[i][j] == '@')
                {
                    si = i;
                    sj = j;
                }
            }
        }

        bool vis[m][n][targetStatus + 1];
        memset(vis, 0, sizeof(vis));
        queue<nodeInfo> que;
        que.push({si, sj, 0});
        int time = 0;
        int dires[] = {-1, 0, 1, 0, -1};

        while(!que.empty())
        {
            int k = que.size();
            while(k--)
            {
                nodeInfo cur = que.front();
                if(cur.keysInfo == targetStatus)
                    return time;
                que.pop();

                for(int d = 0; d < 4; ++d)
                {
                    int i = cur.x + dires[d]; 
                    int j = cur.y + dires[d + 1];
                    int sta = cur.keysInfo;
                    if(i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == '#' || vis[i][j][sta])
                        continue;
                    if(grid[i][j] >= 'A' && grid[i][j] <= 'F')
                    {
                        if(((sta >> (grid[i][j] - 'A')) & 1) == 0)
                            continue;
                    }
                    if(grid[i][j] >= 'a' && grid[i][j] <= 'f')
                        sta |= 1 << (grid[i][j] - 'a');

                    vis[i][j][sta] = true;
                    que.push({i, j, sta});
                }
            } 
            ++time;
        }

        return -1;
    }
};