typedef pair<int, int> pii;

class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {

        int n = nums.size();
        pii dp[n + 1][4];
        int pre[n + 1];
        pre[0] = 0;
        for(int i = 0; i < n; ++i)
            pre[i + 1] = pre[i] + nums[i];

        for(int i = k - 1; i < n; ++i)
        {
            for(int j = 0; j < 4; ++j)
            {
                dp[i + 1][j].first = dp[i][j].first;
                dp[i + 1][j].second = dp[i][j].second;
            }
            for(int j = 1; j < 4; ++j)
            {
                int preK = pre[i + 1] - pre[i - k + 1];
                if(dp[i - k + 1][j - 1].first + preK > dp[i + 1][j].first)
                {
                    dp[i + 1][j].first = dp[i - k + 1][j - 1].first + preK;
                    dp[i + 1][j].second = i - k + 1;
                }
            }
        }


        vector<int> ans;
        int cur = dp[n][3].second;
        int m = 3;
        while(m--)
        {
            ans.emplace_back(cur);
            cur = dp[cur][m].second;
        }

        reverse(ans.begin(), ans.end());
        return ans;
        
    }
};