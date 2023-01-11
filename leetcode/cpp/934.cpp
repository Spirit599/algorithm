typedef pair<int, int> pii;

class Solution {
public:
    int shortestBridge(vector<vector<int>>& grid) {



        queue<pii> que;
        int m = grid.size();
        int n = grid[0].size();

        function<void(int, int)> dfs = [&](int i, int j) -> void {

            if(i < 0 || i >= m || j < 0 || j >= n || grid[i][j] != 1)
                return ;
            que.push(make_pair(i, j));
            grid[i][j] = 2;
            dfs(i + 1, j);
            dfs(i - 1, j);
            dfs(i, j + 1);
            dfs(i, j - 1);
        };
        
        for(int i = 0; i < m; ++i)
        {
            bool quit = false;
            for(int j = 0; j < n; ++j)
            {
                if(grid[i][j] == 1)
                {
                    dfs(i, j);
                    quit = true;
                    break;
                }
            }
            if(quit)
                break;
        }



        int dires[] = {-1, 0, 1, 0, -1};
        int ans = -1;

        while(!que.empty()) 
        {
            int k = que.size();
            printf("%d\n", que.size());
            ++ans;
            while(k--)
            {
                pii cur = que.front();
                que.pop();
                for(int d = 0; d < 4; ++d)
                {
                    int i = cur.first + dires[d];
                    int j = cur.second + dires[d + 1];

                    if(i < 0 || i >= m || j < 0 || j >= n)
                        continue;
                    if(grid[i][j] == 1)
                        return ans;
                    else if(grid[i][j] != 0)
                        continue;
                    grid[i][j] = 3;

                    que.push(make_pair(i, j));
                }
            }
        }

        return -1;


    }
};