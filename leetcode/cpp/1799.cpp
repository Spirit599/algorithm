class Solution {
public:
    int maxScore(vector<int>& nums) {

        int n = nums.size();
        int S = 1 << n;
        int dp[S];
        memset(dp, -1, sizeof(dp));

        function<int(int, int)> dfs = [&](int curS, int depth) -> int {

            if(dp[curS] != -1)
                return dp[curS];

            int ret = 0;
            for(int i = 0; i < n; ++i)
            {
                if(curS & (1 << i))
                    continue;
                for(int j = i + 1; j < n; ++j)
                {
                    if(curS & (1 << j))
                        continue;
                    ret = max(ret, gcd(nums[i], nums[j]) * depth + dfs(curS | (1 << i) | (1 << j), depth + 1));
                }
            }

            return dp[curS] = ret;

        };

        return dfs(0, 1);


    }
};