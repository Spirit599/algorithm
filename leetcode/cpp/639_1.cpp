const long long MOD = 1000000007;

class Solution {
public:
    int check_single(char c)
    {
        if(c == '*')
            return 9;
        else if(c == '0')
            return 0;
        else
            return 1;
    }

    int check_double(char c1, char c2)
    {
        if(c1 == '*' && c2 == '*')
            return 15;

        if(c1 == '*')
        {
            if(c2 >= '0' && c2 <= '6')
                return 2;
            else
                return 1;
        }

        if(c2 == '*')
        {
            if(c1 == '1')
                return 9;
            else if(c1 == '2')
                return 6;
            else 
                return 0;
        }

        int cur = (c1 - '0') * 10 + c2 - '0';

        cout<<cur<<endl;

        return cur >= 10 && cur <= 26;


    }
    int numDecodings(string s) {

        int s_size = s.size();
        long long ret = 0;
        long long dp[s_size];
        memset(dp, 0, sizeof(dp));

        dp[0] = check_single(s[0]);
        if(s_size == 1)
            return dp[0];

        dp[1] = check_single(s[0]) * check_single(s[1]) + check_double(s[0], s[1]);

        for (int i = 2; i < s_size; ++i)
        {
            dp[i] = dp[i - 1] * check_single(s[i]) % MOD + dp[i - 2] * check_double(s[i - 1], s[i]) % MOD;
            dp[i] %= MOD;
        }

        return dp[s_size - 1];
    }
};