// dp
// 安排

class Solution {
public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());
        int m = factory.size();
        int n = robot.size();
        long long dp[m + 1][n + 1];

        memset(dp, 0x3f, sizeof(dp));
        dp[0][0] = 0;

        for(int i = 0; i < m; ++i)
        {
            for(int j = 0; j <= n; ++j)
            {
                long long dis = 0;
                for(int k = j - 1; k >= 0; --k)
                {
                    if(j - k > factory[i][1])
                        break;
                    dis += abs(factory[i][0] - robot[k]);
                    dp[i + 1][j] = min(dp[i + 1][j], dp[i][k] + dis);
                }
                dp[i + 1][j] = min(dp[i + 1][j], dp[i][j]);
            }     
        }

        return dp[m][n];
    }
};