// 分组背包DP

class Solution {
public:
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        
        int dp[k + 1];
        memset(dp, 0, sizeof(dp));

        for(auto& pile : piles)
        {
            int n = pile.size();
            for(int i = 1; i < n; ++i)
                pile[i] += pile[i - 1];

            for(int w = k; w >= 0; --w)
            {
                for(int i = 0; i < n; ++i)
                {
                    if(w - i - 1 >= 0)
                        dp[w] = max(dp[w], dp[w - i - 1] + pile[i]);
                }
            }

        }

        return dp[k];
    }
};