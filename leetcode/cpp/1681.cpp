class Solution {
public:
    int minimumIncompatibility(vector<int>& nums, int k) {

        int n = nums.size();
        // if(n == k)
        //     return 0;
        int batch = n / k;
        bool vis[n + 1];
        memset(vis, 0, sizeof(vis));
        int S = 1 << n;
        int dp[S];
        memset(dp, -1, sizeof(dp));
        int inf = 0x3f3f3f3f;
        int vaildStates[S];
        memset(vaildStates, -1, sizeof(vaildStates));

        
        // vector<pair<int, int>> states;

        function<void(int, int, int, int, int)> dfs1 = [&](int depth, int pre, int cur, int maxx, int minn) {

            if(depth == batch)
            {
                vaildStates[cur] = maxx - minn;
                return ;
            }

            for(int i = pre; i < n; ++i)
            {
                if(!vis[nums[i]])
                {
                    vis[nums[i]] = true;
                    dfs1(depth + 1, i + 1, cur | (1 << i), max(maxx, nums[i]), min(minn, nums[i]));
                    vis[nums[i]] = false;
                }
            }
        };
        dfs1(0, 0, 0, 0, n + 1);
        // printf("%d\n", states.size());



        function<int(int)> dfs = [&](int s) -> int {

            if(dp[s] != -1)
                return dp[s];
            if(s == S - 1)
                return 0;

            int ret = inf;
            int remainState = (S - 1) ^ s;
            for(int mask = remainState; mask; mask = (mask - 1) & remainState)
            {
                if(vaildStates[mask] != -1)
                {
                    ret = min(ret, dfs(mask | s) + vaildStates[mask]);
                }
            }

            return dp[s] = ret;
        };

        dfs(0);

        if(dp[0] >= inf)
            return -1;
        else
            return dp[0];
    }
};