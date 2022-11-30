class Solution {
public:
    int numberOf2sInRange(int n) {

        int base = 1;
        int ans = 0;

        while(base < n)
        {
            base = 10 * base;
            ans += n / base * base / 10;
            int cur = n % base;
            printf("%d %d %d\n", ans, base, cur);
            ans += min(base / 10, max(cur - 2 * base / 10 + 1, 0));
        }

        return ans;
    }
};