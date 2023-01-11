class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {

        int n1 = s1.size();
        int n2 = s2.size();
        int n3 = s3.size();
        if(n1 + n2 != n3)
            return false;

        bool dp[n1 + 1][n2 + 1];
        memset(dp, 0, sizeof(dp));
        dp[0][0] = true;
        for(int i = 1; i <= n3; ++i)
        {
            for(int j = 0; j <= min(i, n1); ++j)
            {
                int k = i - j;
                if(k >= n2)
                    continue;
                if(j >= 1 && dp[j - 1][k] && s3[i - 1] == s1[j - 1])
                    dp[j][k] = true;
                if(k >= 1 && dp[j][k - 1] && s3[i - 1] == s2[k - 1])
                    dp[j][k] = true;
                printf("%d %d %d\n", j,k,dp[j][k]);
            }
        }
        return dp[n1][n2];


    }
};