class Solution {
public:
    long long arrangement(int k)
    {
        long long ans = 1;
        int n = 9;
        for(int i = 1; i <= k; ++i)
        {
            ans *= n;
            --n;
        }

        return ans;

    }
    int countNumbersWithUniqueDigits(int n) {

        long long dp[9];
        dp[0] = 1;

        for(int i = 1; i < 9; ++i)
        {
            dp[i] = dp[i - 1] + 9 * arrangement(i - 1);
        }

        return dp[n];


    }
};