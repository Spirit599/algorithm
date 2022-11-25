class Solution {
public:
    long long computeNum(long long num)
    {
        long long base = 5;
        long long ans = 0;
        while(base <= num)
        {
            ans += num / base;
            base *= 5;
        }

        return ans;
    }
    long long haveKZero(int k)
    {
        long long high = LONG_MAX;
        long long low = 0;

        while(high != low)
        {
            long long mid = (high - low) / 2 + low;
            long long cnt = computeNum(mid);
            if(cnt >= k)
                high = mid;
            else
                low = mid + 1;

        }
        return low;
    }
    int preimageSizeFZF(int k) {

        return haveKZero(k + 1) - haveKZero(k);
    }
};