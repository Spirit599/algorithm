class Solution {
public:
    int cutOffTree(vector<vector<int>>& forest) {

        vector<pair<int, int>> vpii;
        int m = forest.size();
        int n = forest[0].size();

        for(int i = 0; i < m; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                if(forest[i][j] > 1)
                    vpii.emplace_back(i, j);
            }
        }
        sort(vpii.begin(), vpii.end(), [&](const pair<int, int>& p1, const pair<int, int>& p2){ return forest[p1.first][p1.second] < forest[p2.first][p2.second];});
        int ans = 0;
        bool vis[55][55];
        int dires[] = {-1, 0, 1, 0, -1};

        auto bfs = [&](pair<int, int>& p1, pair<int, int>& p2) -> int {

            int ret = 0;
            queue<pair<int, int>> que;
            que.emplace(p1.first, p1.second);
            vis[p1.first][p1.second] = true;
            int time = 0;

            while(!que.empty())
            {
                int k = que.size();
                while(k--)
                {
                    auto [x, y] = que.front();
                    if(x == p2.first && y == p2.second)
                        return time;
                    que.pop();
                    for(int d = 0; d < 4; ++d)
                    {
                        int i = x + dires[d];
                        int j = y + dires[d + 1];
                        if(i < 0 || i >= m || j < 0 || j >= n || forest[i][j] == 0 || vis[i][j])
                            continue;
                        vis[i][j] = true;
                        que.emplace(i, j);
                    }
                }
                ++time;
            }
            return -1;
        };

        int vpiiSize = vpii.size();
        pair<int, int> pre = make_pair(0, 0);
        for(int i = 0; i < vpiiSize; ++i)
        {
            memset(vis, 0, sizeof(vis));
            int ret = bfs(pre, vpii[i]);
            // printf("ret = %d\n", ret);
            if(ret == -1)
                return -1;
            ans += ret;
            pre = vpii[i];
        }

        return ans;
    }
};