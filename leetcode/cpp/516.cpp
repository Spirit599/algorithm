class Solution {
public:
    int longestPalindromeSubseq(string s) {

        int n = s.size();
        int dp[n][n];
        memset(dp, -1, sizeof(dp));

        function<int(int, int)> partiton = [&](int left, int right) {

            if(left > right)
                return 0;
            else if(left == right)
                return 1;

            if(dp[left][right] != -1)
                return dp[left][right];

            // printf("%d %d\n", left, right);

            int ret;
            if(s[left] == s[right])
                ret = partiton(left + 1, right - 1) + 2;
            else
                ret = max(partiton(left, right - 1), partiton(left + 1, right));

            return dp[left][right] = ret;
        };

        return partiton(0, n - 1);
    }

};