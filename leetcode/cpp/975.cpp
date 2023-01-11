class Solution {
public:
    int oddEvenJumps(vector<int>& arr) {

        int n = arr.size();
        bool dp[n][2];
        memset(dp, 0, sizeof(dp));
        dp[n - 1][0] = true;
        dp[n - 1][1] = true;

        map<int, int> memo;
        int ans = 0;
        for(int i = n - 1; i >= 0; --i)
        {
            auto itBig = memo.lower_bound(arr[i]);
            if(itBig != memo.end())
                dp[i][0] = dp[itBig->second][1];

            auto itSmall = memo.upper_bound(arr[i]);
            if(itSmall != memo.begin())
                dp[i][1] = dp[(--itSmall)->second][0];

            if(dp[i][0])
                ++ans;
            memo[arr[i]] = i;
        }
        return ans;
    }
};