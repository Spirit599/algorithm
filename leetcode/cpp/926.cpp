class Solution {
public:
    int minFlipsMonoIncr(string s) {

        int dp0 = 0;
        int dp1 = 0;

        for(char c : s)
        {
            int ndp0 = dp0;
            int ndp1 = min(dp0, dp1);
            if(c == '0')
                ++ndp1;
            else
                ++ndp0;
            dp0 = ndp0;
            dp1 = ndp1;
        }

        return min(dp0, dp1);
    }
};