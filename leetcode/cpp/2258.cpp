class Solution {
public:
    int maximumMinutes(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();
        int timeToFire[m][n];
        bool vis[m][n];
        memset(timeToFire, 0x3f, sizeof(timeToFire));

        queue<pair<int, int>> que;
        for(int i = 0; i < m; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                if(grid[i][j] == 1)
                {
                    que.push(make_pair(i, j));
                }
            }
        }

        int time = 0;
        int dires[] = {-1, 0, 1, 0, -1};
        while(!que.empty())
        {
            int k = que.size();
            while(k--)
            {
                int x = que.front().first;
                int y = que.front().second;
                que.pop();
                timeToFire[x][y] = time;
                // printf("%d %d %d\n", x,y,time);
                for(int d = 0; d < 4; ++d)
                {
                    int i = x + dires[d];
                    int j = y + dires[d + 1];
                    if(i >= m || i < 0 || j >= n || j < 0 || grid[i][j] == 2)
                        continue;
                    if(time + 1 >= timeToFire[i][j])
                        continue;
                    //timeToFire[i][j] = time;
                    que.push(make_pair(i, j));
                    
                }
                
            }
            ++time;
        }

        function<bool(int)> check = [&](int mid) -> bool {


            // if(timeToFire[0][0] <= mid)
            //     return false;
            memset(vis, 0, sizeof(vis));
            queue<pair<int, int>> que;
            int time = mid;
            // printf("%d\n", time);
            que.push(make_pair(0, 0));
            while(!que.empty())
            {
                int k = que.size();
                while(k--)
                {
                    int x = que.front().first;
                    int y = que.front().second;
                    que.pop();
                    // printf("%d %d %d\n", x,y,time);
                    if(x == m - 1 && y == n - 1 && timeToFire[x][y] >= time)
                        return true;
                    if(timeToFire[x][y] <= time)
                        continue;
                    
                    for(int d = 0; d < 4; ++d)
                    {
                        int i = x + dires[d];
                        int j = y + dires[d + 1];
                        if(i >= m || i < 0 || j >= n || j < 0 || grid[i][j] == 2 || vis[i][j])
                            continue;
                        //timeToFire[i][j] = time;
                        vis[i][j] = true;
                        que.push(make_pair(i, j));
                        //printf("%d %d %d\n", i,j,time);
                    }
                    
                }
                ++time;
            }

            return false;
        };

        int low = -1;
        int high = n * m + 1;
        while(low != high)
        {
            int mid = (low + high + 1) >> 1;
            if(check(mid))
                low = mid;
            else
                high = mid - 1;
        }

        if(low != n * m + 1)
            return low;
        else
            return 1000000000;
    }
};