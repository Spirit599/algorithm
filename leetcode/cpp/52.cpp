class Solution {
public:
    int totalNQueens(int n) {

        bool cols[n];
        bool diagonal1[2 * n];
        bool diagonal2[2 * n];
        memset(cols, 0, sizeof(cols));
        memset(diagonal1, 0, sizeof(diagonal1));
        memset(diagonal2, 0, sizeof(diagonal2));

        
        int ans = 0;

        function<void(int)> dfs = [&](int x) {

            if(x == n)
            {
                ++ans;
                return ;
            }

            for(int y = 0; y < n; ++y)
            {
                int dia1 = x + y;
                int dia2 = n - x + y;
                if(!cols[y] && !diagonal1[dia1] && !diagonal2[dia2])
                {
                    cols[y] = true;
                    diagonal1[dia1] = true;
                    diagonal2[dia2] = true;
                    dfs(x + 1);
                    cols[y] = false;
                    diagonal1[dia1] = false;
                    diagonal2[dia2] = false;
                }
            }
        };

        dfs(0);

        return ans;
    }
};