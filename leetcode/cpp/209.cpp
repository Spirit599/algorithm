// 二分

class Solution {
public:
    bool check(int len, vector<int>& nums, int target)
    {
        if(nums[len - 1] >= target)
            return true;
        int n = nums.size();
        for(int i = len; i < n; ++i)
        {
            if(nums[i] - nums[i - len] >= target)
                return true;
        }
        return false;
    }
    int minSubArrayLen(int target, vector<int>& nums) {

        int sum = 0;
        for(int& num : nums)
        {
            sum += num;
            num = sum;
        }

        int high = nums.size() + 1;
        int low = 1;
        while(high != low)
        {
            int mid = (high + low) >> 1;
            if(check(mid, nums, target))
                high = mid;
            else
                low = mid + 1;
        }

        if(high != nums.size() + 1)
            return high;
        else
            return 0;
    }
};