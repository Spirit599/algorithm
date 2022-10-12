class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {

        int n = triangle.size();

        int ans = INT_MAX;
        for(int i = 1; i < n; ++i)
        {
            // printf("%d\n", i);
            triangle[i][0] += triangle[i - 1][0];
            int m = triangle[i].size();
            for(int j = 1; j < m - 1; ++j)
            {
                // printf("%d %d\n", i, j);
                triangle[i][j] += min(triangle[i - 1][j], triangle[i - 1][j - 1]);
            }
            triangle[i][m - 1] += triangle[i - 1][m - 2];
        }


        int m = triangle[n - 1].size();
        for(int j = 0; j < m; ++j)
            ans = min(ans, triangle[n - 1][j]);

        return ans;
    }
};