class Solution {
public:
    double eps = 1e-7;
    int minSkips(vector<int>& dist, int speed, int hoursBefore) {

        int n = dist.size();
        double dp[n + 1][n + 1];
        for(int i = 0; i <= n; ++i)
        {
            for(int j = 0; j <= n; ++j)
            {
                dp[i][j] = 1e9 + 1;
            }
        }

        for(int i = 0; i <= n; ++i)
            dp[0][i] = 0;

        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j <= i + 1; ++j)
            {
                double dis = dist[i];
                double t = dis / speed;
                if(j)
                    dp[i + 1][j] = min(ceil(dp[i][j] + t - eps), (dp[i][j - 1] + t));
                else
                    dp[i + 1][j] = ceil(dp[i][j] + t - eps);
            }
        }

        if(dp[n][n - 1] > hoursBefore)
            return -1;

        for(int i = 0; i <= n - 1; ++i)
        {

            int hour = ceil(dp[n][i] - eps);
            if(hour <= hoursBefore)
                return i;
        }

        return 0;


    }
};