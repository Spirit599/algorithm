class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        
        long long low = 0;
        long long high = 1e15 / n;
        long long mid;

        auto check = [&]() -> bool {

            long long sum = 0;
            for(long long bat : batteries)
                sum += min(bat, mid);
            if(n * mid <= sum)
                return true;
            else
                return false;
        };

        while(low != high)
        {
            mid = (high + low + 1) >> 1;
            if(check())
                low = mid;
            else
                high = mid - 1;
        }

        return low;
    }
};