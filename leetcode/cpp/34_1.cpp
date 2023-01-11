class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {

        if(nums.size() == 0)
            return {-1, -1};

        vector<int> ans;
        ans.push_back(lower_search(nums, target));
        ans.push_back(upper_search(nums, target));

        return ans;
    }
    int lower_search(vector<int>& nums, int target)
    {
        int low = 0;
        int high = nums.size() - 1;

        while(low != high)
        {
            int mid = (high - low) / 2 + low;
            if(nums[mid] >= target)
                high = mid;
            else if(nums[mid] < target)
                low = mid + 1;
        }

        if(target == nums[low])
            return low;
        else
            return -1;
    }
    int upper_search(vector<int>& nums, int target)
    {
        int low = 0;
        int high = nums.size() - 1;

        while(low != high)
        {
            int mid = (high - low + 1) / 2 + low;
            if(nums[mid] > target)
                high = mid - 1;
            else if(nums[mid] <= target)
                low = mid;
        }

        if(target == nums[low])
            return low;
        else
            return -1;
    }
};