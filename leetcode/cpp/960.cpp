class Solution {
public:
    int minDeletionSize(vector<string>& strs) {

        int n = strs.size();
        
        int m = strs[0].size();
        int dp[m];
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;
        int ans = 1;

        for(int i = 1; i < m; ++i)
        {
            for(int j = 0; j < i; ++j)
            {
                bool ok = true;
                for(int k = 0; k < n; ++k)
                {
                    if(strs[k][j] > strs[k][i])
                    {
                        ok = false;
                        break;
                    }
                }
                if(ok)
                    dp[i] = max(dp[i], dp[j]);
            }
            ++dp[i];
            ans = max(ans, dp[i]);
        }

        return  m - ans;
    }


};