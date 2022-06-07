class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {

        int high = *max_element(piles.begin(), piles.end());
        int low = 1;

        while(low < high)
        {
            int mid = (high - low) / 2 + low;
            //cout<<low<<" "<<mid<<" "<<high<<endl;

            if(check(piles, h, mid))
            {
                high = mid;
            }
            else
            {
                low = mid + 1;
            }
        }
        return low;
    }

    bool check(vector<int>& piles, int h, int mid)
    {
        int sum_h = 0;
        for(int pile : piles)
        {
            sum_h += ceil((double)pile / mid);
            if(sum_h > h)
                return false;
        }
        return true;
    }
};