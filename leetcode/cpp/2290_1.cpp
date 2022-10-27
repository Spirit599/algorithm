// deque
// 01BFS

class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();
        int dires[] = {-1, 0, 1, 0, -1};

        int dis[m][n];
        memset(dis, 0x3f, sizeof(dis));

        deque<pair<int, int>> deq;
        deq.push_front(make_pair(0, 0));
        dis[0][0] = grid[0][0];

        while(!deq.empty())
        {
            auto [x, y] = deq.front();
            deq.pop_front();
            for(int d = 0; d < 4; ++d)
            {
                int i = x + dires[d];
                int j = y + dires[d + 1];
                if(i < 0 || i >= m || j < 0 || j >= n)
                    continue;
                if(dis[x][y] + grid[i][j] >= dis[i][j])
                    continue;
                dis[i][j] = dis[x][y] + grid[i][j];
                if(!grid[i][j])
                    deq.push_front(make_pair(i, j));
                else
                    deq.push_back(make_pair(i, j));
            }

        }

        return dis[m - 1][n - 1];
    }
};