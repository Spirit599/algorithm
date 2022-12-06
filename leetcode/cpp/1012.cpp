class Solution {
public:
    int numDupDigitsAtMostN(int n) {


        string strN = to_string(n);
        int len = strN.size();
        int S = 1 << 10;
        int dp[len][S];
        memset(dp, -1, sizeof(dp));

        function<int(int, int, bool, bool)> dfs = [&](int depth, int curS, bool hasNum, bool isLimited) {

            if(depth == len)
                return hasNum ? 1 : 0;
            if(hasNum && !isLimited && dp[depth][curS] != -1)
                return dp[depth][curS];

            int ret = 0;
            if(!hasNum)
                ret += dfs(depth + 1, curS, false, false);

            int start = hasNum ? 0 : 1;
            int end = isLimited ? strN[depth] - '0' : 9;
            for(int i = start; i <= end; ++i)
            {
                if(((curS >> i) & 1) == 0)
                {
                    ret += dfs(depth + 1, curS | (1 << i), true, isLimited && end == i);
                }
            };

            return dp[depth][curS] = ret;
        };

        return n - dfs(0, 0, false, true);
    }
};