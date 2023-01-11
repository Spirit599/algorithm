class Solution {
public:
    int maxValue(int n, int index, int maxSum) {

        int left = index;
        int right = n - index - 1;

        int low = 1;
        int high = maxSum;

        auto getSum = [&](int ll, int rr) -> long long {

            int len = rr - ll + 1;
            if(len & 1)
                return 1ll * (rr + ll) / 2 * len;
            else
                return 1ll * (rr + ll) * len / 2;
        };

        auto check = [&](int mid) -> bool {

            long long sum = mid;
            --mid;
            if(mid >= left)
                sum += getSum(mid - left + 1, mid);
            else
                sum += getSum(1, mid) + left - mid;
            
            if(sum > maxSum)
                return false;

            if(mid >= right)
                sum += getSum(mid - right + 1, mid);
            else
                sum += getSum(1, mid) + right - mid;

            if(sum > maxSum)
                return false;

            return true;

        };

        while(low != high)
        {
            int mid = (low + high + 1) >> 1;
            if(check(mid))
                low = mid;
            else
                high = mid - 1;
        }
        return low;
    }
};