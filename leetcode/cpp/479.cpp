class Solution {
public:
    int largestPalindrome(int n) {

        if(n == 1)
            return 9;

        int upLimit = pow(10, n) - 1;
        for(int left = upLimit; ; --left)
        {
            long long pali = left;
            int x = left;
            while(x)
            {
                pali = 10 * pali + x % 10;
                x /= 10;
            }
            printf("%lld\n", pali);
            for(long long x = upLimit; x * x >= pali; --x)
            {
                if(pali % x == 0)
                {
                    return pali % 1337;
                }
            }
        }
    }
};