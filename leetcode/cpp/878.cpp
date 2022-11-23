class Solution {
public:
    int nthMagicalNumber(int n, int a, int b) {

        int c = lcm(a, b);
        long long low = min(a, b);
        long long high = 1ll * min(a, b) * n;

        auto check = [&](long long mid) -> bool {

            if(mid / a + mid / b - mid / c >= n)
                return true;
            else
                return false;
        };

        while(low != high)
        {
            long long mid = (low + high) >> 1;
            if(check(mid))
                high = mid;
            else
                low = mid + 1;
        }

        const int MOD = 1e9 + 7;
        return low % MOD;
    }
};