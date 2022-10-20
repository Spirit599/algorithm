class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
        
        int high = *max_element(nums.begin(), nums.end());
        int low = 0;

        while(high != low)
        {
            int mid = (high + low) / 2;
            if(check(mid, nums))
                high = mid;
            else
                low = mid + 1;
        }
        return high;
    }
    bool check(int mid, vector<int>& nums)
    {
        int n = nums.size();
        int k = 0;
        for(int i = n - 1; i >= 0; --i)
        {
            if(nums[i] > mid)
                k += nums[i] - mid;
            else
                k = max(k + nums[i] - mid, 0);
        }
        if(k > 0)
            return false;
        else
            return true;
    }
};