class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {

        int n = arr.size();
        int dp[n][n];
        memset(dp, 0, sizeof(dp));
        unordered_map<int, int> memo;
        // dp[0] = 1;
        // dp[1] = 1;
        memo[arr[0]] = 0;
        memo[arr[1]] = 1;
        int ans = 0;

        for(int i = 2; i < n; ++i)
        {
            memo[arr[i]] = i;
            for(int j = i - 1; j >= 0; --j)
            {
                int dif = arr[i] - arr[j];
                if(dif >= arr[j])
                    break;
                auto it = memo.find(dif);
                if(it == memo.end())
                    continue;
                dp[i][j] = max(dp[i][j], dp[j][it->second] + 1);
                //printf("%d %d %d\n", arr[i],arr[j],dp[i][j]);
                ans = max(ans, dp[i][j]);
            }
        }
        if(ans != 0)
            return ans + 2;
        else
            return 0;
    }
};