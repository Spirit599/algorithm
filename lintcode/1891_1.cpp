// 1891 · 旅行计划

class Solution {
public:
    /**
     * @param arr: the distance between any two cities
     * @return: the minimum distance Alice needs to walk to complete the travel plan
     */
    int travelPlan(vector<vector<int>> &arr) {
        

        int n = arr.size();
        int S_size = 1 << n;
        int dp[n][S_size];
        memset(dp, 0x3f, sizeof(dp));

        dp[0][1] = 0;
        for(int S = 1; S < S_size; ++S)
        {
            for(int i = 0; i < n; ++i)
            {
                if(S & (1 << i))
                {
                    for (int j = 0; j < n; ++j)
                    {
                        if(!(S & (1 << j)))
                        {
                            dp[j][S | (1 << j)] = min(dp[j][S | (1 << j)], dp[i][S] + arr[i][j]);
                        }
                    }
                }
            }
        }

        int ans = 0x7fffffff;
        for(int i = 0; i < n; ++i)
        {
            ans = min(ans, dp[i][S_size - 1] + arr[i][0]);
        }

        return ans;
    }
};