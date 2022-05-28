class Solution {
public:
    int minDistance(string word1, string word2) {

        int ret = 0;

        int word2_len = word2.size();
        int word1_len = word1.size();

        if(word1_len > word2_len)
        {
            swap(word1_len, word2_len);
            swap(word1, word2);
        }


        int dp[word1_len + 1][word2_len + 1];
        memset(dp, 0, sizeof(dp));

        for (int i = 1; i <= word1_len; ++i)
        {
            for (int j = 1; j <= word2_len; ++j)
            {
                if(word1[i - 1] == word2[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                else
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        //cout<<dp[word1_len][word2_len]<<endl;


        ret = word1_len + word2_len - 2 * dp[word1_len][word2_len];

        return ret;
    }
};