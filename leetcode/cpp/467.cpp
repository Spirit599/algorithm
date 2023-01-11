class Solution {
public:
    int findSubstringInWraproundString(string p) {

        int n = p.size();
        int maxLength[26];
        int dp[n];
        memset(dp, 0, sizeof(dp));
        memset(maxLength, 0, sizeof(maxLength));

        dp[0] = 1;
        maxLength[p[0] - 'a'] = 1;

        for(int i = 1; i < n; ++i)
        {
            if(p[i] == p[i - 1] + 1 || p[i] == p[i - 1] - 25)
            {
                dp[i] = dp[i - 1] + 1;
                maxLength[p[i] - 'a'] = max(maxLength[p[i] - 'a'], dp[i]);
            }
            else
            {
                dp[i] = 1;
                maxLength[p[i] - 'a'] = max(maxLength[p[i] - 'a'], dp[i]);
            }
            printf("%d\n", dp[i]);
        }

        int ans = 0;
        for(int i = 0; i < 26; ++i)
            ans += maxLength[i];
        return ans;
    }
};