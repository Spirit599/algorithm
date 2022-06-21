// 395 · 硬币排成线 II

class Solution {
public:
    /**
     * @param values: a vector of integers
     * @return: a boolean which equals to true if the first player will win
     */
    bool firstWillWin(vector<int> &values) {
        
        int n = values.size();
        if(n <= 2)
        	return true;

        int dp[n];
        dp[n - 1] = 0;
        dp[n - 2] = 0;
        int sum = values[n - 1] + values[n - 2];

        for(int i = n - 3; i >= 0; --i)
        {
        	offensive = max(dp[i + 1] + values[i], dp[i + 2] + values[i] + values[i + 1]);
        	sum += values[i];
        	dp[i] = sum - offensive;
        }
        cout<<dp[0]<<endl;

        return 2 * dp[0] <= sum;
    }
};