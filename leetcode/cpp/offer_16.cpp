//快速幂


class Solution {
public:
    double myPow(double x, int n) {

        double ans = 1;
        long long m = n;
        m = max(m, -m);
        while(m)
        {
            if(m & 1)
                ans *= x;
            m = m >> 1;
            x *= x;
        }
        if(n >= 0)
            return ans;
        else
            return 1 / ans;
    }
};