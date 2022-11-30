struct nodeInfo
{
    int x;
    int y;
    int block;
};

int dires[] = {-1, 0, 1, 0, -1};

class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {

        int m = grid.size();
        int n = grid[0].size();
        int vis[m][n];
        memset(vis, 0x3f, sizeof(vis));
        queue<nodeInfo> que;
        que.push({0, 0, 0});
        vis[0][0] = 0;

        int time = 0;
        while(!que.empty())
        {
            int queSize = que.size();
            while(queSize--)
            {
                nodeInfo cur = que.front();
                if(cur.x == m - 1 && cur.y == n - 1)
                    return time;
                que.pop();
                for(int d = 0; d < 4; ++d)
                {
                    int i = cur.x + dires[d];
                    int j = cur.y + dires[d + 1];
                    int blocked = cur.block;
                    if(i >= m || i < 0 || j >= n || j < 0 || vis[i][j] <= blocked)
                        continue;
                    if(grid[i][j] == 1)
                        ++blocked;
                    if(blocked > k)
                        continue;
                    vis[i][j] = blocked;
                    que.push({i, j, blocked});
                }
            }
            ++time;
        }

        return -1;
    }
};