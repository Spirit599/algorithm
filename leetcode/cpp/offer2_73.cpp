class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {

        int low = 1;
        int high = *max_element(piles.begin(), piles.end());

        while(low != high)
        {
            int mid = (low + high) / 2;
            if(check(mid, piles, h))
                high = mid;
            else
                low = mid + 1;
        }
        return low;
    }

    bool check(int mid, vecor<int>& piles, int h)
    {
        int cnt = 0;
        for(int pile : piles)
        {
            if(pile % mid)
                cnt += pile / mid + 1;
            else
                cnt += pile / mid;
            if(cnt > h)t
                return false;
        }
        return true;
    }
};