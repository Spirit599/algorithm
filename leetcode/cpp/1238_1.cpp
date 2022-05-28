class Solution {
public:
    vector<int> circularPermutation(int n, int start) {
        vector<int> ret;

        int length = pow(2, n);
        int dp[length];
        dp[0] = 0;
        dp[1] = 1;
        int symmetry = 0;

        for (int i = 2; i < length; i *= 2)
            dp[i] = i;


        for (int i = 2; i < length; ++i)
        {
            if(dp[i] != i)
            {
                int index = 2 * symmetry - i;
                dp[i] = dp[i - 1] + (dp[index - 1] - dp[index]);
            }
            else
            {
                dp[i] += dp[i - 1];
                symmetry = i;
            }
        }

        bool flag = false;
        for(int i = 0; i < length; ++i)
        {
            if(dp[i] == start)
            {
                ret.push_back(dp[i]);
                flag = true;
            }
            else
            {
                if(flag)
                    ret.push_back(dp[i]);
            }
        }

        for(int i = 0; i < length; ++i)
        {
            if(dp[i] != start)
                ret.push_back(dp[i]);
            else
                break;
        }

        return ret;
    }
};