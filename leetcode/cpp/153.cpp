class Solution {
public:
    int findMin(vector<int>& nums) {

        int low = 0;
        int high = nums.size() - 1;

        while(low != high)
        {
            int mid = (low + high) >> 1;
            if(nums[high] < nums[mid])
                low = mid + 1;
            else
                high = mid;
        }

        return nums[low];
    }
};