class Solution {
public:
    int removeBoxes(vector<int>& boxes) {

        int n = boxes.size();
        int dp[n][n][n];
        memset(dp, -1, sizeof(dp));

        function<int(int, int, int)> dfs = [&](int start, int end, int k) {

            if(start > end)
                return 0;
            if(dp[start][end][k] != -1)
                return dp[start][end][k];

            int ret = dfs(start, end - 1, 0) + (k + 1) * (k + 1);
            for(int i = start; i < end; ++i)
            {
                if(boxes[i] == boxes[end])
                {
                    ret = max(ret, dfs(start, i, k + 1) + dfs(i + 1, end - 1, 0));
                }
            }

            return dp[start][end][k] = ret;
        };

        return dfs(0, n - 1, 0);
    }

};