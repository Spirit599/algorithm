class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        
        int high = *max_element(candies.begin(), candies.end());
        int low = 0;

        while(high != low)
        {
            int mid = (high + low + 1) >> 1;
            if(check(mid, candies, k))
                low = mid;
            else
                high = mid - 1;
        }
        return low;
    }
    bool check(int mid, vector<int>& candies, long long k)
    {
        if(mid == 0)
            return true;
        long long cnt = 0;
        for(int num : candies)
        {
            cnt += num / mid;
            if(cnt >= k)
                return true;
        }
        return false;
    }
};