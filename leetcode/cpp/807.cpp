class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();
        int maxm[m];
        memset(maxm, 0, sizeof(maxm));
        int maxn[n];
        memset(maxn, 0, sizeof(maxn));

        for(int i = 0; i < m; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                maxm[i] = max(maxm[i], grid[i][j]);
                maxn[j] = max(maxn[j], grid[i][j]);
            }
        }

        int ans = 0;
        for(int i = 0; i < m; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                ans += max(min(maxm[i], maxn[j]) - grid[i][j], 0);
            }
        }
        return ans;
    }
};