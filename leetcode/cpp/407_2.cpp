struct cood
{
    int x;
    int y;
    int z;
};

struct cmp_cood {
    bool operator() (const cood& co1, const cood& co2) const
    {
        return co1.z > co2.z;
    }
};

int dires[] = {-1, 0, 1, 0, -1};

class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {

        int m = heightMap.size();
        int n = heightMap[0].size();
        bool vis[m][n];
        memset(vis, 0, sizeof(vis));

        priority_queue<cood, vector<cood>, cmp_cood> pq;
        for(int i = 0; i < m; ++i)
        {
            pq.push({0, i, heightMap[i][0]});
            pq.push({n - 1, i, heightMap[i][n - 1]});
            vis[i][0] = true;
            vis[i][n - 1] = true;
        }
        for(int j = 1; j < n; ++j)
        {
            pq.push({j, 0, heightMap[0][j]});
            pq.push({j, m - 1, heightMap[m - 1][j]});
            vis[0][j] = true;
            vis[m - 1][j] = true;
        }

        int ans = 0;

        while(!pq.empty())
        {
            cood cur = pq.top();
            pq.pop();
            for(int i = 0; i < 4; ++i)
            {
                int x = cur.x + dires[i];
                int y = cur.y + dires[i + 1];
                if(x < 0 || x >= n || y < 0 || y >= m || vis[y][x])
                    continue;
                vis[y][x] = true;
                ans += max(cur.z - heightMap[y][x], 0);
                pq.push({x, y, max(heightMap[y][x], cur.z)});
            }
        }

        return ans;
    }
};