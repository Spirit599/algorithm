typedef pair<int, int> pii;
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {

        int dires[] = {-1, 0, 1, 0, -1};
        int m = grid.size();
        int n = grid[0].size();
        queue<pii> que;
        int k = 0;
        for(int i = 0; i < m; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                if(grid[i][j] == 1)
                    ++k;
                else if(grid[i][j] == 2)
                    que.emplace(i, j);
            }
        }

        int time = 0;
        while(!que.empty() && k)
        {
            ++time;
            int sum = que.size();
            while(sum--)
            {
                auto [x, y] = que.front();
                que.pop();
                for(int d = 0; d < 4; ++d)
                {
                    int i = x + dires[d];
                    int j = y + dires[d + 1];
                    if(i >= m || i < 0 || j >= n || j < 0 || grid[i][j] != 1)
                        continue;
                    --k;
                    grid[i][j] = 2;
                    que.emplace(i, j);
                }
            }
        }

        if(!k)
            return time;
        else
            return -1;

    }
};