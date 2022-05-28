typedef long long ll;

class Solution {
public:
    int arrangeCoins(int n) {

        int low = 1;
        int high = n;

        while(low < high)
        {
            int mid = (high - low + 1) / 2 + low;
            if((ll)mid * (mid + 1) <= (ll)2 * n)
            {
                low = mid;
            }
            else
            {
                high = mid - 1;
            }
        }

        return low;
    }
};