// 剑指 Offer 43. 1～n 整数中 1 出现的次数

class Solution {
public:
    int countDigitOne(int n) {

        long long k = n;
        long long base = 1;

        long long ans = 0;
        while(k >= base)
        {
            ans += k / (10 * base) * base;
            ans += max(min(k % (10 * base) - base + 1 , base), 0ll);
            base = 10 * base;

        }

        return ans;
    }
};