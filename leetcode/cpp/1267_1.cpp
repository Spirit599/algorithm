class Solution {
public:
    int countServers(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        bool row[m];
        memset(row, 0, sizeof(row));

        bool column[n];
        memset(column, 0, sizeof(column));

        for (int i = 0; i < m; ++i)
        {
            int nums = 0;
            for (int j = 0; j < n; ++j)
            {
                if(grid[i][j] == 1)
                    ++nums;
                if(nums == 2)
                    break;
            }
            if(nums == 2)
                row[i] = true;
        }

        for (int i = 0; i < n; ++i)
        {
            int nums = 0;
            for (int j = 0; j < m; ++j)
            {
                if(grid[j][i] == 1)
                    ++nums;
                if(nums == 2)
                    break;
            }
            if(nums == 2)
                column[i] = true;
        }

        int ans = 0;
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if(grid[i][j] && (row[i] || column[j]))
                {
                    //cout<<i<<" "<<j<<endl;
                    ++ans;
                }
            }

        }

        return ans;
    }
};
