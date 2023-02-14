class Solution {
public:
    int maximizeWin(vector<int>& prizePositions, int k) {
        
        int n = prizePositions.size();
        int dp[n + 1];
        memset(dp, 0, sizeof(dp));

        int left = 0;
        int ans = 0;
        for(int right = 0; right < n; ++right)
        {
            while(prizePositions[right] - prizePositions[left] > k)
                ++left;
            ans = max(ans, right - left + 1 + dp[left]);
            dp[right + 1] = max(dp[right], right - left + 1);
        }

        return ans;
    }
};