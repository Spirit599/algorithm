#define MAX_INT (2147483647)

class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {

        if(k == 1)
            return 0;

        int ret = MAX_INT;

        sort(nums.begin(), nums.end());

        int nums_size = nums.size();

        for (int i = 0; i + k - 1 < nums_size; ++i)
        {
            ret = min(ret, nums[i + k - 1] - nums[i]);
        }
        return ret;
    }
};