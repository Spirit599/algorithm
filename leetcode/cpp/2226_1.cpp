class Solution {
public:
    bool check(vector<int>& candies, long long k, long long mid)
    {
        if(mid == 0)
            return true;

        long long cur = 0;
        for(int candy : candies)
        {
            cur += candy / mid;
            if(cur >= k)
                return true;
        }
        return false;
    }

    int maximumCandies(vector<int>& candies, long long k) {

        long long all_sum = 0;
        for(int candy : candies)
            all_sum += candy;

        long long high = all_sum / k + 1;
        long long  low = 0;

        while(high != low)
        {
            long long mid = low + (high - low + 1) / 2;
            if(check(candies, k, mid))
                low = mid;
            else
                high = mid - 1;
        }


        return low;
    }
};