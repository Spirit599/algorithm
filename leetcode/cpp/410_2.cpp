class Solution {
public:

	bool judge(vector<int>& nums, int m, int mid)
    {
        int capacity = mid;
        for(int i : nums)
        {
            if(capacity - i >= 0)
            {
                capacity = capacity - i;
            }
            else
            {
                capacity = mid - i;
                --m;
                if(m == 0)
                    return false;
            }
        }
        return true;
    }
    
    int splitArray(vector<int>& nums, int m) {

    	int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);


        while(low != high)
        {
            int mid = low + (high - low) / 2;
            //cout<<low<<" "<<high<<endl;
            if(judge(nums, m, mid))
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