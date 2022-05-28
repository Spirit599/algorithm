class Solution {
public:
    int countQuadruplets(vector<int>& nums) {

        long long ret = 0;

        for (int i = 0; i < nums.size(); ++i)
        {
            /* code */
            for (int j = i + 1; j < nums.size(); ++j)
            {
                /* code */
                for (int k = j + 1; k < nums.size(); ++k)
                {
                    /* code */
                    for (int l = k + 1; l < nums.size(); ++l)
                    {
                        /* code */
                        if(nums[i] + nums[j] + nums[k] == nums[l])
                            ret++;
                    }
                }
            }
        }

        return  ret;
    }
};