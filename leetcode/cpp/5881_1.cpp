class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        
        int ret = -1;
        for (int i = 0; i < nums.size(); ++i)
        {
            /* code */
            for (int j = i + 1; j < nums.size(); ++j)
            {
                /* code */
                if(nums[j] > nums[i])
                    ret = max(ret, nums[j] - nums[i]);
            }
        }

        return ret;
    }
};