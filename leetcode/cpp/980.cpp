// 状态压缩

class Solution {
public:
    int uniquePathsIII(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();
        
        int si = -1;
        int sj = -1;
        map<pair<int, int>, int> coodToIndex;
        int index = 0;
        vector<pair<int, int>> indexToCood;
        for(int i = 0; i < m; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                if(grid[i][j] == 0)
                {
                    coodToIndex.emplace(make_pair(i, j), index);
                    indexToCood.emplace_back(make_pair(i, j));
                    ++index;
                }
                else if(grid[i][j] == 1)
                {
                    si = i;
                    sj = j;
                }
            }
        }
        coodToIndex.emplace(make_pair(si, sj), index);
        indexToCood.emplace_back(make_pair(si, sj));

        int zeroSize = indexToCood.size();
        int S = (1 << zeroSize);
        int dp[zeroSize][S];
        memset(dp, -1, sizeof(dp));
        int dires[] = {-1, 0, 1, 0, -1};

        function<int(int, int)> dfs = [&](int curIndex, int curS) {

            if(curS == S - 1 && curIndex == -1)
                return 1;
            if(dp[curIndex][curS] != -1)
                return dp[curIndex][curS];
            
            int ret = 0;
            auto [i, j] = indexToCood[curIndex];
            for(int k = 0; k < 4; ++k)
            {
                int x = i + dires[k];
                int y = j + dires[k + 1];
                if(x >= m || x < 0 || y >= n || y < 0 || grid[x][y] == 1 || grid[x][y] == -1)
                    continue;
                if(grid[x][y] == 2)
                {
                    if(curS == S - 1)
                        ret += dfs(-1, curS);
                    continue;
                }
                int index = coodToIndex[make_pair(x, y)];
                if(((curS >> index) & 1) == 0)
                    ret += dfs(index, curS | (1 << index));
            }
            return dp[curIndex][curS] = ret;
        };

        return dfs(zeroSize - 1, 1 << (zeroSize - 1));
    }
};