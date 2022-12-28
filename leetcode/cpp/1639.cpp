class Solution {
public:
    int numWays(vector<string>& words, string target) {

        int n1 = words[0].size();
        int n2 = target.size();
        if(n1 < n2)
            return 0;

        int cnt[n1][26];
        memset(cnt, 0, sizeof(cnt));
        for(string& str : words)
        {
            for(int i = 0; i < n1; ++i)
            {
                ++cnt[i][str[i] - 'a'];
            }
        }

        int mod = 1e9 + 7;
        long long dp[n1 + 1][n2 + 1];
        memset(dp, 0, sizeof(dp));
        dp[0][0] = 1;

        for(int i = 0; i < n1; ++i)
        {
            memcpy(dp[i + 1], dp[i], sizeof(dp[i + 1]));
            for(int j = 0; j < min(i+1, n2); ++j)
            {
                dp[i + 1][j + 1] += dp[i][j] * cnt[i][target[j] - 'a'];
                dp[i + 1][j + 1] %= mod;
                
            }
        }



        return dp[n1][n2];
    }
};