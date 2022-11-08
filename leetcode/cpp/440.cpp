// 字典序排序

class Solution {
public:
    int getStep(int cur, long long n) {

        long long first = cur;
        long long last = cur;
        int step = 0;

        while(first <= n) 
        {
            step += min(n, last) - first + 1;
            first = first * 10;
            last = last * 10 + 9;
        }
        return step;
    }
    int findKthNumber(int n, int k) {

        int cur = 1;
        --k;

        while(k)
        {
            int step = getStep(cur, n);
            if(step <= k)
            {
                k -= step;
                ++cur;
            }
            else
            {
                --k;
                cur = cur * 10;
            }
        }

        return cur;
    }
};