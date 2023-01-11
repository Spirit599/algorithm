class Solution {
public:
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        
        int n = piles.size();
        int dp[n + 1][k + 1];
        memset(dp, 0, sizeof(dp));

        for(int i = 0; i < n; ++i)
        {
            auto& pile = piles[i];
            
        }        
    }
};