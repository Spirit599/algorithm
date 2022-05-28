class Solution {
public:
    int translateNum(int num) {

        string str = to_string(num);
        int n = str.size();
        if(n == 0)
            return 0;
        int dp[n + 1];
        memset(dp, 0, sizeof(dp));
        cout<<"---------"<<endl;
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i <= n; ++i)
        {
            
            if(str[i - 2] >= '3' || str[i - 2] == '0')
            {
                dp[i] = dp[i - 1];
            }
            else
            {
                if(str[i - 2] != '2')
                {
                    dp[i] = dp[i - 2] + dp[i - 1];
                }
                else
                {
                    if(str[i - 1] <= '5')
                    {
                        dp[i] = dp[i - 2] + dp[i - 1];
                    }
                    else
                    {
                        dp[i] = dp[i - 1];
                    }
                }
            }
            cout<<str[i - 2]<<" "<<str[i - 1]<<endl;
            cout<<dp[i]<<endl;
        }

        return dp[n];
    }
};