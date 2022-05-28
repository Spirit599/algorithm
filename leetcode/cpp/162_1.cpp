class Solution {
public:
    int findPeakElement(vector<int>& nums) {

        int low =  0;
        int high = nums.size();
        int cur = low + (high - low) / 2;

        while(low != high)
        {
            if(nums[cur]  > nums[cur + 1])
            {
                high = cur;
            }
            else
            {
                low = cur + 1;
            }
            cur = low + (high - low) / 2;
        }

        return low;

    }
};