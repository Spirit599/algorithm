class Solution {
public:
    int minimumDistance(string word) {

        int n = word.size();
        int dp[n][26][27];
        memset(dp, 0x3f, sizeof(dp));
        dp[0][word[0] - 'A'][26] = 0;

        auto getCost = [](int a, int b) -> int {

            int x1 = a / 6;
            int y1 = a % 6;
            int x2 = b / 6;
            int y2 = b % 6;
            return abs(x1 - x2) + abs(y1 - y2);
        };

        for(int i = 1; i < n; ++i)
        {
            char c = word[i];
            for(int j = 0; j < 26; ++j)
            {
                int cost = getCost(j, c - 'A');
                for(int k = 0; k < 27; ++k)
                {
                    dp[i][c - 'A'][k] = min(dp[i][c - 'A'][k], dp[i - 1][j][k] + cost);
                    // printf("%d %d %d\n", dp[i][c - 'A'][k] , dp[i - 1][j][k] , cost);
                }

            }


            for(int j = 0; j < 26; ++j)
            {
                int cost = getCost(j, c - 'A');
                for(int k = 0; k < 26; ++k)
                    dp[i][k][c - 'A'] = min(dp[i][k][c - 'A'], dp[i - 1][k][j] + cost);
            }

            for(int j = 0; j < 26; ++j)
            {
                dp[i][j][c - 'A'] = min(dp[i][j][c - 'A'], dp[i - 1][j][26]);
            }
        }

        int ans = INT_MAX;
        for(int i = 0; i < 26; ++i)
        {
            for(int j = 0; j < 27; ++j)
            {
                ans = min(ans, dp[n - 1][i][j]);
            }
        }

        return ans;
    }
};