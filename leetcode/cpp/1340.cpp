class Solution {
public:
    int maxJumps(vector<int>& arr, int d) {

        int n = arr.size();
        int dp[n];
        memset(dp, -1, sizeof(dp));

        function<int(int)> dfs = [&](int cur) -> int {

            if(dp[cur] != -1)
                return dp[cur];

            int ret = 0;
            for(int i = cur - 1; i >= 0 && cur - i <= d && arr[cur] > arr[i]; --i)
            {
                ret = max(ret, dfs(i));
            }
            for(int i = cur + 1; i < n && i - cur <= d && arr[cur] > arr[i]; ++i)
            {
                ret = max(ret, dfs(i));
            }

            return dp[cur] = ret + 1;
        }

        int ans = -1;
        for(int i = 0; i < n; ++i)
            ans = max(ans, dfs(i));

        return ans;
    }
};