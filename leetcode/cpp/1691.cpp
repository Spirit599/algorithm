class Solution {
public:
    int maxHeight(vector<vector<int>>& cuboids) {

        int n = cuboids.size();
        int dp[n];
        memset(dp, 0, sizeof(dp));
        for(auto& cuboid : cuboids)
            sort(cuboid.begin(), cuboid.end());
        sort(cuboids.begin(), cuboids.end());


        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j < i; ++j)
            {
                if(cuboids[j][1] <= cuboids[i][1] && cuboids[j][2] <= cuboids[i][2])
                {
                    dp[i] = max(dp[i], dp[j]);
                }
            }
            dp[i] += cuboids[i][2];
        }


        return *max_element(dp, dp + n);
    }
};