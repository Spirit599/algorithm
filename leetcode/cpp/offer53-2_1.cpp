class Solution {
public:
    int missingNumber(vector<int>& nums) {

        // long long sum = 0;
        // long long n = nums.size();
        // for (int i = 0; i < n; ++i)
        // {
        //     sum += nums[i];
        // }

        // return n * (n + 1) / 2 - sum;
        int high = nums.size() - 1;
        int low = 0;
        while(low != high)
        {
            int mid = (high - low + 1) / 2 + low;
            if(nums[mid] == mid)
            {
                low = mid;
            }
            else
            {
                high = mid - 1;
            }
        }
        return low == nums[low] ? low + 1 : 0;

    }
};