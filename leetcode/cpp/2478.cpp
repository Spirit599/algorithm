// 动态规划

const int MOD = 1e9 + 7;

class Solution {
public:
	bool isPrime(char c) {

		if(c == '2' || c == '3' || c == '5' || c == '7')
			return true;
		else
			return false;
	}
    int beautifulPartitions(string s, int k, int minLength) {
        
        int n = s.size();
    	if(!isPrime(s[0]) || isPrime(s[n - 1]))
    		return 0;

    	int dp[k + 1][n + 1];
    	memset(dp, 0, sizeof(dp));
    	dp[0][0] = 1;

    	for(int i = 1; i <= k; ++i)
    	{
    		int sum = 0;
    		for(int j = 0; j < n; ++j)
    		{
    			if(j - minLength + 1 >= 0)
    			{
    				sum += dp[i - 1][j - minLength + 1];
    				sum = sum % MOD;
    			}
    			if(j == n - 1 || (!isPrime(s[j]) && isPrime(s[j + 1])))
    				dp[i][j + 1] = sum;

    		}
    	}

    	return dp[k][n];

    }
};
