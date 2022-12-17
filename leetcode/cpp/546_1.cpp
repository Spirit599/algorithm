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

            int end1 = end;
            int k1 = k;
            while(end1 > start && boxes[end1] == boxes[end1 - 1])
            {
                --end1;
                ++k1;
            }

            int ret = dfs(start, end1 - 1, 0) + (k1 + 1) * (k1 + 1);
            for(int i = start; i < end1; ++i)
            {
                if(boxes[i] == boxes[end1])
                {
                    ret = max(ret, dfs(start, i, k1 + 1) + dfs(i + 1, end1 - 1, 0));
                }
            }

            return dp[start][end][k] = ret;
        };

        return dfs(0, n - 1, 0);
    }

};