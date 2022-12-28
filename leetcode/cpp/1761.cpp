class Solution {
public:
    int minTrioDegree(int n, vector<vector<int>>& edges) {

        bool edgess[n + 1][n + 1];
        memset(edgess, 0, sizeof(edgess));
        int degress[n + 1];
        memset(degress, 0, sizeof(degress));
        for(auto& edge : edges)
        {
            edgess[edge[0]][edge[1]] = true;
            edgess[edge[1]][edge[0]] = true;
            ++degress[edge[0]];
            ++degress[edge[1]];
        }

        int ans = INT_MAX;
        for(int x = 1; x <= n; ++x)
        {
            for(int y = x + 1; y <= n; ++y)
            {
                for(int z = y + 1; z <= n; ++z)
                {
                    if(edgess[x][z] && edgess[z][y] && edgess[y][x])
                    {
                        ans = min(ans, degress[x] + degress[y] + degress[z] - 6);
                    }
                }
            }
        }

        if(ans != INT_MAX)
            return ans;
        else
            return -1;

    }
};