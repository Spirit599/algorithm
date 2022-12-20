class Solution {
public:
    int numSquarefulPerms(vector<int>& nums) {


        int n = nums.size();
        int S = 1 << n;
        int dp[n][S];
        memset(dp, -1, sizeof(dp));
        bool vis[n];
        memset(vis, 0, sizeof(vis));

        int ans = 0;
        function<int(int, int)> dfs = [&](int cur, int curS) -> int {

            if(curS == S - 1)
                return 1;
            if(dp[cur][curS] != -1)
                return dp[cur][curS];

            int ret = 0;
            for(int i = 0; i < n; ++i)
            {
                if(vis[i] || (i && nums[i] == nums[i - 1] && !vis[i - 1]))
                    continue;
                int num = nums[cur] + nums[i];
                double sqrtNum = sqrt(num);
                if(sqrtNum == (int)sqrtNum)
                {
                    vis[i] = true;
                    ret += dfs(i, curS | (1 << i));
                    vis[i] = false;
                }
            }

            return dp[cur][curS] = ret;
        };

        sort(nums.begin(), nums.end());
        for(int i = 0; i < n; ++i)
        {
            if(i && nums[i] == nums[i - 1])
                continue;
            vis[i] = true;
            ans += dfs(i, 1 << i);
            vis[i] = false;
        }

        return ans;
    }
};