// lcp

class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {

        int m = nums1.size();
        int n = nums2.size();
        int dp[m + 1][n + 1];
        memset(dp, 0, sizeof(dp));

        int ans = 0;
        for(int i = m - 1; i >= 0; --i)
        {
            for(int j = n - 1; j >= 0; --j)
            {
                if(nums1[i] == nums2[j])
                    dp[i][j] = dp[i + 1][j + 1] + 1;
                ans = max(ans, dp[i][j]);
            }
        }
        return ans;
    }
};