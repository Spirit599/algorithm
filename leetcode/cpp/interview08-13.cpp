class Solution {
public:
    int pileBox(vector<vector<int>>& box) {

        sort(box.begin(), box.end(), greater<>());
        int n = box.size();
        int dp[n];
        memset(dp, 0, sizeof(dp));
        int ans = 0;

        dp[0] = box[0][2];
        ans = dp[0];

        for(int i = 1; i < n; ++i)
        {
            for(int j = 0; j < i; ++j)
            {
                if(box[j][0] > box[i][0] && box[j][1] > box[i][1] && box[j][2] > box[i][2])
                {
                    dp[i] = max(dp[i], dp[j]);
                }
            }
            dp[i] += box[i][2];
            ans = max(ans, dp[i]);
        }

        return ans;
    }
};