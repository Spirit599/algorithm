class Solution {
public:
    int resolveNum(int n) {

        int num = n;
        int base = 2;
        int ans = 0;
        while(num >= base * base)
        {
            while(num % base == 0)
            {
                num /= base;
                ans += base;
            }
            ++base;
        }

        if(num != 1)
            ans += num;
        return ans;
    }
    int smallestValue(int n) {
        
        while(1)
        {
            int m = resolveNum(n);
            if(m == n)
                return n;
            n = m;
        }
        return -1;

    }
};