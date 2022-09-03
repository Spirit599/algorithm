// 32. 最长有效括号

class Solution {
public:
    int longestValidParentheses(string s) {

    	int n = s.size();
    	int dp[n + 1];
    	memset(dp, 0, sizeof(dp));
    	int ans = 0;

        for(int i = 1; i < n; ++i)
        {
        	if(s[i] == ')')
        	{
        		if(s[i - 1] == '(')
        		{
        			dp[i + 1] = dp[i - 1] + 2;
        		}
        		else if(s[i - 1] == ')')
        		{
        			if(i - dp[i] - 1 >= 0 && s[i - dp[i] - 1] == '(')
        			{
        				dp[i + 1] = dp[i] + dp[i - dp[i] - 1] + 2;
        			}
        			
        		}
        	}
        	ans = max(ans, dp[i + 1]);
        }

    	return ans;
    }
};