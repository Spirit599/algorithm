// 数位DP

class Solution {
public:
    int atMostNGivenDigitSet(vector<string>& digits, int n) {

        string num = to_string(n);
        int len = num.size();
        int dp[len];
        memset(dp, -1, sizeof(dp));

        function<int(int, bool, bool)> dfs = [&](int depth, bool hasNum, bool isLimited) -> int {

            if(depth == len)
                return hasNum ? 1 : 0;
            if(hasNum && !isLimited && dp[depth] != -1)
                return dp[depth];

            int ret = 0;
            if(!hasNum)
                ret += dfs(depth + 1, false, false);

            int start = hasNum ? 0 : 1;
            int end = isLimited ? num[depth] - '0' : 9;
            for(auto& str : digits) {
                int k = str[0] - '0';
                if(k >= start && k <= end) {
                    ret += dfs(depth + 1, true, isLimited && k == end);
                }
            }

            if(hasNum && !isLimited) {
                dp[depth] = ret;
            }
            return ret;
        };

        return dfs(0, 0, false, true);


    }
};