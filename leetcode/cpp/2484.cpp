class Solution {
public:
	
	const int MOD = 1e9 + 7;
    int countPalindromes(string s) {
        
        int n = s.size();

        int pre[10];
        memset(pre, 0, sizeof(pre));
        int suf[10];
        memset(suf, 0, sizeof(suf));

        int prepre[n][10][10];
        memset(prepre, 0, sizeof(prepre));
        int sufsuf[n][10][10];
        memset(sufsuf, 0, sizeof(sufsuf));

        for(int i = 0; i < n; ++i)
        {
        	if(i >= 1)
        	{
        		for(int j = 0; j <= 9; ++j)
		    	{
		    		for(int k = 0; k <= 9; ++k)
		    		{
		    			prepre[i][j][k] = prepre[i - 1][j][k];
		    		}
		    	}
        		for(int j = 0; j <= 9; ++j)
        		{
        			if(pre[j] != 0)
        			{
        				prepre[i][s[i] - '0'][j] += pre[j];
        			}
        		}
        	}
        	++pre[s[i] - '0'];
        }
        
        for(int i = n - 1; i >= 0; --i)
        {

        	if(i <= n - 2)
        	{
        		for(int j = 0; j <= 9; ++j)
		    	{
		    		for(int k = 0; k <= 9; ++k)
		    		{
		    			sufsuf[i][j][k] = sufsuf[i + 1][j][k];
		    		}
		    	}
        		for(int j = 0; j <= 9; ++j)
        			sufsuf[i][s[i] - '0'][j] += suf[j];
        	}
        	++suf[s[i] - '0'];
        }

        int ans = 0;
        for(int i = 2; i + 2 < n; ++i)
        {
        	for(int j = 0; j <= 9; ++j)
        	{
        		for(int k = 0; k <= 9; ++k)
        		{
        			ans = (1ll * ans + 1ll * prepre[i - 1][j][k] * sufsuf[i + 1][j][k]) % MOD;
        		}
        	}
        }

        return ans;

    }


};