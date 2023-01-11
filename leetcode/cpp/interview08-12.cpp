class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {

        bool col[n];
        bool diagonal1[2 * n];
        bool diagonal2[2 * n];
        memset(col, 0, sizeof(col));
        memset(diagonal1, 0, sizeof(diagonal1));
        memset(diagonal2, 0, sizeof(diagonal2));

        vector<vector<string>> ret;
        vector<string> cur(n, string(n,'.'));

        function<void(int)> dfs = [&](int x) {

            if(x == n)
            {
                ret.emplace_back(cur);
                return ;
            }

            for(int y = 0; y < n; ++y)
            {
                if(!col[y] && !diagonal1[x + y] && !diagonal2[n - x + y])
                {
                    col[y] = true;
                    diagonal1[x + y] = true;
                    diagonal2[n - x + y] = true;
                    cur[x][y] = 'Q';
                    dfs(x + 1);
                    col[y] = false;
                    diagonal1[x + y] = false;
                    diagonal2[n - x + y] = false;
                    cur[x][y] = '.';
                }
            }
        };

        dfs(0);

        return ret;
    }
};