class Solution {
public:
    const int mod = 1e9 + 7;
    int quickPow(long long x, int k) {

        long long ret = 1;
        while(k)
        {
            if(k & 1)
                ret = ret * x % mod;
            k = k >> 1;
            x = x * x % mod;

        }
        return ret;
    }
    int monkeyMove(int n) {
        
        return (quickPow(2, n) - 2 + mod) % mod;
    }
};