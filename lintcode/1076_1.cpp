//1076 · 两字符串ASCII的最小删除和

class Solution {
public:
    /**
     * @param s1: a string
     * @param s2: a string
     * @return: the lowest ASCII sum of deleted characters to make two strings equal
     */
    int minimumDeleteSum(string &s1, string &s2) {
        
        int sum = 0;
        for(char c : s1)
            sum += c;
        for(char c : s2)
            sum += c;

        int n1 = s1.size();
        int n2 = s2.size();

        int dp[n1 + 1][n2 + 1];
        memset(dp, 0, sizeof(dp));

        for(int i = 1; i <= n1; ++i)
        {
            for(int j = 1; j <= n2; ++j)
            {
                if(s1[i - 1] == s2[j - 1])
                {
                    dp[i][j] = max({dp[i - 1][j - 1] + s1[i - 1], dp[i][j - 1], dp[i - 1][j]});
                }
                else
                {
                    dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
                }   
            }
        }

        return sum - 2 * dp[n1][n2];
    }
};