class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {

        int n = grid.size();
        int ans = 0;

        for(int i = 0; i < n; ++i)
        {
            int maxx = 0;
            int maxxx = 0;
            for(int j = 0; j < n; ++j)
            {
                maxx = max(maxx, grid[i][j]);
                maxxx = max(maxxx, grid[j][i]);
                if(grid[i][j] != 0)
                    ++ans;
            }
            printf("%d %d\n", maxx, maxxx);
            ans += maxx;
            ans += maxxx;
        }

        return ans;
    }
};