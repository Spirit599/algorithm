class Solution {
public:
    int getMaxRepetitions(string s1, int n1, string s2, int n2) {

        int len1 = s1.size();
        int len2 = s2.size();
        int dp[len2];
        memset(dp, 0, sizeof(dp));

        for(int i = 0; i < len2; ++i)
        {
            int k = i;
            for(int j = 0; j < len1; ++j)
            {
                if(s2[k] == s1[j])
                {
                    ++dp[i];
                    k = (k + 1) % len2;
                }
            }
            // printf("%d\n", dp[i]);
        }

        int curIdx = 0;
        int sum = 0;
        for(int i = 0; i < n1; ++i)
        {
            sum += dp[curIdx];
            curIdx = (curIdx + dp[curIdx]) % len2;
        }

        return sum / len2 / n2;
    }
};