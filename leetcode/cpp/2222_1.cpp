class Solution {
public:
    long long numberOfWays(string s) {
        
        long long ans = 0;

        long long zero = 0;
        long long one = 0;

        long long zero_one = 0;
        long long one_zero = 0;

        int n = s.size();


        for(int i = 0; i < n; ++i)
        {
            if(s[i] == '0')
            {
                ans += zero_one;

                ++zero;
                one_zero += one;
            }
            else
            {
                ans += one_zero;

                ++one;
                zero_one += zero;
            }

        }

        return ans;
    }
};