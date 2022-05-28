class Solution {
public:
    bool judge(vector<int>& weights, int days, int mid)
    {
        int capacity = mid;
        for(int i : weights)
        {
            if(capacity - i >= 0)
            {
                capacity = capacity - i;
            }
            else
            {
                capacity = mid - i;
                --days;
                if(days == 0)
                    return false;
            }
        }
        return true;
    }
    int shipWithinDays(vector<int>& weights, int days) {

        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);

        // for(int i : weights)
        // {
        //     low = max(low, i);
        //     high += i;
        // }

        while(low != high)
        {
            int mid = low + (high - low) / 2;
            //cout<<low<<" "<<high<<endl;
            if(judge(weights, days, mid))
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
};