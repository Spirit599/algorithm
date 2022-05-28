class Solution {
private:
    vector<vector<int>> ret;
public:

    void find_end(vector<vector<int>>& land, int start_i, int start_j)
    {
        int m = land.size();
        int n = land[0].size();
        int end_i = start_i;
        int end_j = start_j;
        while(end_i + 1 < m && land[end_i + 1][start_j] == 1)
        {
            end_i++;
        }
        while(end_j + 1 < n && land[start_i][end_j + 1] == 1)
        {
            end_j++;
        }
        for (int i = start_i; i <= end_i; ++i)
        {
            for (int j = start_j; j <= end_j; ++j)
            {
                /* code */
                land[i][j] = 0;
            }
        }
        //cout<<start_i<<start_j<<end_i<<end_j<<endl;
        ret.push_back({start_i, start_j, end_i, end_j});
    }

    vector<vector<int>> findFarmland(vector<vector<int>>& land) {

        int m = land.size();
        int n = land[0].size();

        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if(land[i][j] == 1)
                {
                    find_end(land, i, j);
                }
            }
        }

        return ret;
    }
};