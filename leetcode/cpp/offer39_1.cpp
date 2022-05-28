class Solution {
public:
    int majorityElement(vector<int>& nums) {

        int n = nums.size();

        int cnt = 1;
        int candidate = nums[0];
        for (int i = 1; i < n; ++i)
        {
            if(nums[i] == candidate)
            {
                ++cnt;
            }
            else
            {
                --cnt;
                if(cnt < 0)
                {
                    cnt = 1;
                    candidate = nums[i];
                }
            }
        }


        // cnt = 0;
        // for (int i = 0; i < n; ++i)
        // {
        //     if(candidate == nums[i])
        //         ++cnt;
        // }

//        if(2 * cnt >= n)
            return candidate;
        // else
        //     return -1;
    }
};