// 状态压缩
// __builtin_popcount

class Solution {
public:
    int countArrangement(int n) {

        int S = 1 << n;
        int dp[S];
        memset(dp, -1, sizeof(dp));

        function<int(int ,int)> dfs = [&](int curS, int depth) -> int {

            if(dp[curS] != -1)
                return dp[curS];
            if(depth == n + 1)
                return 1;

            int ret = 0;
            for(int i = 0; i < n; ++i)
            {
                if(((curS >> i) & 1) == 0)
                {
                    int num = i + 1;
                    if(num % depth == 0 || depth % num == 0)
                    {
                        ret += dfs(curS | (1 << i), depth + 1);
                    }
                }
            }

            return dp[curS] = ret;
        };

        return dfs(0, 1);

    }
};