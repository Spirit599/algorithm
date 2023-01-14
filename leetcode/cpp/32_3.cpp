class Solution {
public:
    int longestValidParentheses(string s) {

    	int ans = 0;
        int n = s.size();
        int dp[n + 1];
        memset(dp, 0, sizeof(dp));

        for(int i = 0; i < n; ++i)
        {
            if(s[i] == '(')
            {
                dp[i] = 0;
            }
            else
            {
                if(i - 1 >= 0)
                {
                    if(s[i - 1] == '(')
                    {
                        int preLen = 0;
                        if(i - 2 >= 0)
                            preLen = dp[i - 2];
                        dp[i] = preLen + 2;
                    }
                    else
                    {
                        int preLen = dp[i - 1];
                        int preIdx = i - preLen - 1;
                        if(preIdx >= 0 && s[preIdx] == '(')
                        {
                            dp[i] = preLen + 2;
                            if(preIdx >= 1)
                                dp[i] += dp[preIdx - 1];
                        }
                    }
                }
            }

            ans = max(ans, dp[i]);
        }

    	return ans;

    }
};