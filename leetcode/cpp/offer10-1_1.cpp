const int MOD = 1000000007;
class Solution {
public:
    int fib(int n) {

        if(n == 0)
            return 0;
        if(n == 1)
            return 1;

        int f0 = 0;
        int f1 = 1;
        n = n - 1;
        while(n--)
        {
            int tmp = f0;
            f0 = f1;
            f1 = (tmp + f1) % MOD;
        }
        return f1;
    }
};