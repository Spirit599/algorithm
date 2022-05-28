// #define MAX_INT (2147483647)
// #define MIN_INT (-2147483648)

class Solution {
public:
    int sumOfBeauties(vector<int>& nums) {

        int nums_size = nums.size();

        int ret = 0;

        for (int i = 1; i < nums_size - 1; ++i)
        {
            if(nums[i - 1] < nums[i] && nums[i] < nums[i + 1])
            {
                ret++;
            }
        }

        vector<int> unkonwn(nums_size);
        int left_max = nums[0];

        for (int i = 1; i < nums_size - 1; ++i)
        {
            if(nums[i] > left_max)
            {
                left_max = nums[i];
                ++unkonwn[i];
            }
        }

        int right_min = nums[nums_size - 1];
        for (int i = nums_size - 2; i >= 1; --i)
        {
            if(nums[i] < right_min)
            {
                right_min = nums[i];
                ++unkonwn[i];
            }
        }

        for (int i = 1; i < nums_size - 1; ++i)
        {
            if(unkonwn[i] == 2)
            {
                ret++;
            }
        }

        return ret;
    }
};