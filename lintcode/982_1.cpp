// 982 · 等差切片

class Solution {
public:
    /**
     * @param a: an array
     * @return: the number of arithmetic slices in the array A.
     */
    int numberOfArithmeticSlices(vector<int> &a) {
        
        int n = a.size();
        int dp[n];
        int ans = 0;
        memset(dp, 0, sizeof(dp));

        for (int i = 2; i < n; ++i)
        {
            if(a[i] - a[i - 1] == a[i - 1] - a[i - 2])
            {
                dp[i] = dp[i - 1] + 1;
                ans += dp[i];
            }
        }
        return ans;
    }
};