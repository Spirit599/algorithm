// 512 · 解码方法

class Solution {
public:
    /**
     * @param s: a string,  encoded message
     * @return: an integer, the number of ways decoding
     */
    int numDecodings(string &s) {
        
        int n = s.size();
        if(n == 0)
            return 0;

        int dp[n];
        memset(dp, 0, sizeof(dp));

        if(s[0] >= '1' && s[0] <= '9')
            dp[0] = 1;
        if(n >= 2)
        {
            int num = (s[0] - '0') * 10 + s[1] - '0';
            if(num >= 10 && num <= 26)
                dp[1] = 1;
            else
                dp[1] = 0;

            if(s[1] >= '1' && s[1] <= '9')
                dp[1] += dp[0];
        }

        for(int i = 2; i < n; ++i)
        {
            int num1 = s[i] - '0';
            int num2 = (s[i - 1] - '0') * 10 + s[i] - '0';
            dp[i] = 0;
            if(num1 >= 1 && num1 <= 9)
                dp[i] += dp[i - 1];
            if(num2 >= 10 && num2 <= 26)
                dp[i] += dp[i - 2];
        }

        return dp[n - 1];
    }
};