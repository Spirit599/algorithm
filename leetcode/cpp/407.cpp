typedef pair<int, int> pii;

class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {

        int m = heightMap.size();
        int n = heightMap[0].size();

        bool vis[m][n];
        memset(vis, 0, sizeof(vis));

        auto cood2Idx = [&](int i, int j) -> int {
            return i * n + j;
        };

        priority_queue<pii, vector<pii>, greater<pii>> pq;

        for(int i = 0; i < m; ++i)
        {
            pq.emplace(heightMap[i][0], cood2Idx(i, 0));
            pq.emplace(heightMap[i][n - 1], cood2Idx(i, n - 1));
            vis[i][0] = true;
            vis[i][n - 1] = true;
        }
        for(int j = 1; j < n - 1; ++j)
        {
            pq.emplace(heightMap[0][j], cood2Idx(0, j));
            pq.emplace(heightMap[m - 1][j], cood2Idx(m - 1, j));
            vis[0][j] = true;
            vis[m - 1][j] = true;
        }

        int ans = 0;
        int dires[5] = {-1, 0, 1, 0, -1};
        while(!pq.empty())
        {
            auto [h, idx] = pq.top();
            pq.pop();

            int i = idx / n;
            int j = idx % n;
            for(int k = 0; k < 4; ++k)
            {
                int ii = i + dires[k];
                int jj = j + dires[k + 1];

                if(ii < 0 || ii >= m || jj < 0 || jj >= n || vis[ii][jj])
                    continue;
                vis[ii][jj] = true;
                printf("%d %d %d %d\n", ii,jj,h,heightMap[ii][jj]);
                ans += max(h - heightMap[ii][jj], 0);
                pq.emplace(max(h, heightMap[ii][jj]), cood2Idx(ii, jj));
            }
        }

        return ans;
    }
};