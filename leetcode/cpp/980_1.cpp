typedef pair<int, int> pii;

class Solution {
public:
    int uniquePathsIII(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();
        
        map<pii, int> Cood2Idx;
        vector<pii> Idx2Cood;
        int si,sj;

        for(int i = 0; i < m; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                if(grid[i][j] == 0)
                {
                    Cood2Idx[make_pair(i, j)] = Idx2Cood.size();
                    Idx2Cood.emplace_back(i, j);   
                }
                else if(grid[i][j] == 1)
                {
                    si = i;
                    sj = j;
                }
            }
        }

        Cood2Idx[make_pair(si, sj)] = Idx2Cood.size();
        Idx2Cood.emplace_back(si, sj);
        


        int k = Cood2Idx.size();
        int S = (1 << k);
        int dp[k][S];
        memset(dp, -1, sizeof(dp));

        int dires[] = {-1, 0, 1, 0, -1};

        function<int(int, int, int)> dfs = [&](int i, int j, int curS) -> int {


            int curIndex = Cood2Idx[make_pair(i, j)];
            if(dp[curIndex][curS] != -1)
                return dp[curIndex][curS];

            int ret = 0;
            for(int d = 0; d < 4; ++d)
            {
                int ii = i + dires[d];
                int jj = j + dires[d + 1];
                if(ii < 0 || ii >= m || jj < 0 || jj >= n || grid[ii][jj] == -1)
                    continue;

                if(grid[ii][jj] == 2)
                {
                    if(curS == S - 1)
                        ret += 1;
                }
                else if(grid[ii][jj] == 0)
                {
                    int idx = Cood2Idx[make_pair(ii, jj)];
                    if(curS & (1 << idx))
                        continue;
                    ret += dfs(ii, jj, curS | (1 << idx));
                }
            }
            return dp[curIndex][curS] = ret;
        };

        return dfs(si, sj, (1 << (k - 1)));
    }
};