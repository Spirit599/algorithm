class Solution {
public:
    int tilingRectangle(int n, int m) {


        bool vis[n][m];
        memset(vis, 0, sizeof(vis));
        
        int ans = INT_MAX;

        function<void(int)> dfs = [&](int cnt) {

            if(cnt >= ans)
                return ;

            bool ok = true;
            int x;
            int y;
            for(int i = 0; i < n && ok; ++i)
            {
                for(int j = 0; j < m && ok; ++j)
                {
                    if(!vis[i][j])
                    {
                        ok = false;
                        x = i;
                        y = j;
                    }
                }
            }

            if(ok)
            {
                ans = min(ans, cnt);
                return ;
            }

            int maxLen = min(n - x, m - y);

            for(int len = maxLen; len >= 1; --len)
            {
                bool canInsert = true;
                for(int i = x; i < x + len && canInsert; ++i)
                {
                    for(int j = y; j < y + len && canInsert; ++j)
                    {
                        if(vis[i][j])
                        {
                            canInsert = false;
                        }
                    }
                }

                if(!canInsert)
                    continue;

                for(int i = x; i < x + len; ++i)
                {
                    for(int j = y; j < y + len; ++j)
                    {
                        vis[i][j] = true;
                    }
                }

                dfs(cnt + 1);

                for(int i = x; i < x + len; ++i)
                {
                    for(int j = y; j < y + len; ++j)
                    {
                        vis[i][j] = false;
                    }
                }
            }
        };

        dfs(0);

        return ans;
    }
};