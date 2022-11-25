class Solution {
public:
    int findIntegers(int n) {

        vector<int> arr;
        while(n)
        {
            arr.emplace_back(n % 2);
            n = n >> 1;
        }
        reverse(arr.begin(), arr.end());

        int k = arr.size();
        int dp[k][2];
        memset(dp, -1, sizeof(dp));

        function<int(int, int, bool, bool)> dfs = [&](int depth, int pre, bool hasNum, bool isLimited) -> int {

            if(depth == k)
                return hasNum ? 1 : 0;
            if(!isLimited && hasNum && dp[depth][pre] != -1)
                return dp[depth][pre];
            
            int ret = 0;
            if(!hasNum)
                ret += dfs(depth + 1, 0, false, false);

            int start = hasNum ? 0 : 1;
            int end = isLimited ? arr[depth] : 1;
            for(int i = start; i <= end; ++i)
            {
                if(i == 1 && pre == 1)
                    continue;
                ret += dfs(depth + 1, i, true, isLimited && i == end);
            }

            if(!isLimited && hasNum)
                dp[depth][pre] = ret;

            return ret;

        };

        return dfs(0, 0, false, true) + 1;
    }
};