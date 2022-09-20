// 2376. 统计特殊整数
// 数位DP

class Solution {
public:
    int countSpecialNumbers(int n) {
        
        string num = to_string(n);
        int len = num.size();
        int dp[len][1 << 10];
        memset(dp, -1, sizeof(dp));

        function<int(int, int, bool, bool)> dfs = [&](int depth, int mask, bool hasNum, bool isLimited) -> int {

            if(depth == len)
                return hasNum ? 1 : 0;
            if(!isLimited && hasNum && dp[depth][mask] != -1)
                return dp[depth][mask];

            int ret = 0;
            if(!hasNum)
                ret += dfs(depth + 1, mask, false, false);

            int start = hasNum ? 0 : 1;
            int end = isLimited ? num[depth] - '0' : 9;
            for(int i = start; i <= end; ++i)
            {
                if((mask >> i & 1) == 0)
                {
                    ret += dfs(depth + 1, mask | (1 << i), true, isLimited && i == end);
                }
            }

            if(hasNum && !isLimited)
                dp[depth][mask] = ret;

            return ret;
        };

        return dfs(0, 0, false, true);
    }
};