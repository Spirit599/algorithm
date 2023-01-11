class Solution {
public:
    int maximumRequests(int n, vector<vector<int>>& requests) {


        int m = requests.size();
        int S = (1 << m);
        int ans = 0;
        int vis[n];

        auto check = [&](int s) -> bool {

            memset(vis, 0, sizeof(vis));
            for(int i = 0; i < m; ++i)
            {
                if(((s >> i) & 1) == 1)
                {
                    ++vis[requests[i][0]];
                    --vis[requests[i][1]];
                }
            }
            for(int i = 0; i < n; ++i)
                if(vis[i] != 0)
                    return false;

            return true;
        };

        for(int i = 1; i < S; ++i)
        {
            int w = __builtin_popcount(i);
            if(w <= ans)
                continue;
            if(check(i))
                ans = w;
        }

        return ans;

    }
};