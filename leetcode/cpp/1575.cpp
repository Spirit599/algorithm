class Solution {
public:
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {

        int n = locations.size();
        int dp[n][fuel + 1];
        memset(dp, -1, sizeof(dp));
        int mod = 1e9 + 7;

        function<int(int, int)> dfs = [&](int cur, int fu) -> int {

            if(dp[cur][fu] != -1)
                return dp[cur][fu];


            int ret = 0;
            if(cur == finish)
                ++ret;
            for(int i = 0; i < n; ++i)
            {
                int dis = abs(locations[i] - locations[cur]);
                if(i != cur && dis <= fu)
                {
                    ret += dfs(i, fu - dis);
                    ret %= mod;
                }
            }

            return dp[cur][fu] = ret;
        };

        return dfs(start, fuel);
    }
};