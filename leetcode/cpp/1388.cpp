class Solution {
public:
    int helper(vector<int>& arr, int ll, int rr) {

        int num = (rr - ll + 2);
        num = num / 3;
        int dp[rr + 5][num + 1];
        memset(dp, 0, sizeof(dp));

        for(int i = ll; i <= rr; ++i)
        {
            for(int j = 1; j <= num; ++j)
            {
                dp[i + 2][j] = max(dp[i + 1][j], dp[i][j - 1] + arr[i]);
            }
        }

        return dp[rr + 2][num];
    }
    int maxSizeSlices(vector<int>& slices) {

        int n = slices.size();
        return max(helper(slices, 0, n - 2), helper(slices, 1, n - 1));
    }
};