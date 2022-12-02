class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {


        stoneValue.emplace_back(0);
        stoneValue.emplace_back(0);
        stoneValue.emplace_back(0);
        int n = stoneValue.size();


        int dp[n];
        dp[n - 1] = stoneValue[n - 1];
        dp[n - 2] = stoneValue[n - 2] + dp[n - 1];
        dp[n - 3] = stoneValue[n - 3] + dp[n - 2];


        for(int i = n - 4; i >= 0; --i)
        {
            dp[i] = max({stoneValue[i] - dp[i + 1],
                        stoneValue[i] + stoneValue[i + 1] - dp[i + 2],
                        stoneValue[i] + stoneValue[i + 1] + stoneValue[i + 2] - dp[i + 3]});
        }

        if(dp[0] > 0)
            return "Alice";
        else if(dp[0] < 0)
            return "Bob";
        else
            return "Tie";
    }
};