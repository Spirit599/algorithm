class Solution {
public:
    int getRank(int m, int n, int num) {

        int ret = 0;
        int x = 1;
        int y = n;

        while(y)
        {
            while(x <= m && num >= x * y)
                ++x;
            ret += x - 1;
            y--;
        }
        return ret;
    }
    int findKthNumber(int m, int n, int k) {

        int high = m * n;
        int low = 1;

        while(high != low)
        {
            int mid = (high + low) / 2;
            if(getRank(m, n, mid) >= k)
                high = mid;
            else
                low = mid + 1;
        }

        return low;
    }
};