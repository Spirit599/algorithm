#二分

class Solution {
public:
    bool isPerfectSquare(int num) {

        long long high = 100000;
        long long low = 1;

        while(low <= high)
        {
            long long mid = low + (high - low) / 2;
            if(mid * mid == num)
            {
                return true;
            }
            else if(mid * mid < num)
            {
                low = mid + 1;
            }
            else if(mid * mid > num)
            {
                high = mid - 1;
            }
        }
        return false;
    }
};