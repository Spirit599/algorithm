class Solution {
public:
    int countDigitOne(int n) {

        long long base = 1;
        int ans = 0;

        while(n >= base)
        {
            int cnt = n / (10 * base);
            ans += cnt * base;

            int remain = n % (10 * base);
            ans += min(max(remain - base + 1, 0ll), base); 
            base *= 10;
        }

        return ans;
    }
};