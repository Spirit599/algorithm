class Solution {
public:
    int weight(int k)
    {
        int ans = 0;
        while(k)
        {
            ans += k % 10;
            k = k / 10;
        }
        return  ans;
    }
    int movingCount(int m, int n, int k) {

        bool visit[m][n];
        memset(visit, 0, sizeof(visit));


        int ans = 0;
        queue<pair<int, int>> que;
        que.push({0, 0});
        visit[0][0] = true;
        ++ans;

        int dires[] = {1, 0, -1, 0, 1};
        while(!que.empty())
        {
            auto cur = que.front();
            que.pop();
            for (int l = 0; l < 4; ++l)
            {
                int i = cur.first + dires[l];
                int j = cur.second + dires[l + 1];
                if(i >= 0 && i < m && j >= 0 && j < n && weight(i) + weight(j) <= k && !visit[i][j])
                {
                    ++ans;
                    visit[i][j] = true;
                    que.push({i, j});
                }
            }
        }

        return ans;
    }
};