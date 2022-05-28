//优先队列
//接雨水
typedef pair<int, int> pii;

class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {

        int m = heightMap.size();
        int n = heightMap[0].size();

        if(m <= 2 || n <= 2)
            return 0;

        bool visit[m][n];
        memset(visit, 0, sizeof(visit));

        priority_queue<pii, vector<pii>, greater<pii>> pri_que;
        for (int i = 0; i < m; ++i)
        {
            pri_que.push({heightMap[i][0], i * n + 0});
            pri_que.push({heightMap[i][n - 1], i * n + n - 1});
            visit[i][0] = true;
            visit[i][n - 1] = true;
        }
        for (int j = 1; j < n - 1; ++j)
        {
            pri_que.push({heightMap[0][j], 0 * n + j});
            pri_que.push({heightMap[m - 1][j], (m - 1) * n + j});
            visit[0][j] = true;
            visit[m - 1][j] = true;
        }
        //cout<<pri_que.size()<<endl;

        int ans = 0;
        int dires[] = {-1, 0, 1, 0, -1};
        while(!pri_que.empty())
        {
            pii curr = pri_que.top();
            pri_que.pop();
            for (int k = 0; k < 4; ++k)
            {
                int i = curr.second / n + dires[k];
                int j = curr.second % n + dires[k + 1];
                if(i >= 0 && i < m && j >= 0 && j < n && !visit[i][j])
                {
                    ans += max(curr.first - heightMap[i][j], 0);
                    visit[i][j] = true;
                    pri_que.push({max(curr.first, heightMap[i][j]), i * n + j});
                }
            }
        }

        return ans;
    }
};