//392 · 打劫房屋

class Solution {
public:
    /**
     * @param a: An array of non-negative integers
     * @return: The maximum amount of money you can rob tonight
     */
    long long houseRobber(vector<int> &a) {
        
        int n = a.size();
        if(n == 0)
            return 0;
   
        long long dp[n];
        dp[0] = a[0];
        dp[1] = max(a[0], a[1]);
        for(int i = 2; i < n; ++i)
            dp[i] = max(dp[i - 1], dp[i - 2] + a[i]);

        return dp[n - 1];

    }
};