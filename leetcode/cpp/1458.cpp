class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {

        int n1 = nums1.size();
        int n2 = nums2.size();
        int dp[n1][n2];
        memset(dp, 0xbf, sizeof(dp));

        for(int i = 0; i < n1; ++i)
        {
            for(int j = 0; j < n2; ++j)
            {
                int pre = 0;
                if(i && j)
                    pre = max(dp[i - 1][j - 1], pre);
                dp[i][j] = pre + nums1[i] * nums2[j];
                if(i)
                    dp[i][j] = max(dp[i][j], dp[i - 1][j]);
                if(j)
                    dp[i][j] = max(dp[i][j], dp[i][j - 1]);
            }
        }

        return dp[n1 - 1][n2 - 1];
    }
};