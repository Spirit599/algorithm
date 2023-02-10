class Solution {
public:
    int minCost(vector<int>& nums, int k) {
        
        int n = nums.size();
        int dp[n + 1];
        dp[0] = 0;
        int state[n];

        for(int i = 0; i < n; ++i)
        {
            memset(state, 0, sizeof(state));
            int maxx = INT_MAX;
            int single = 0;
            for(int j = i; j >= 0; --j)
            {
                int val = nums[j];
                if(state[val] == 0)
                {
                    state[val] = 1;
                    ++single;
                }
                else if(state[val] == 1)
                {
                    state[val] = 2;
                    --single;
                }
                int len = i - j + 1;

                maxx = min(maxx, dp[j] + (len - single) + k);
            }
            dp[i + 1] = maxx;
        }

        return dp[n];
    }
};