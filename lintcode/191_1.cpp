//dp
//子序列 乘积

class Solution {
public:
    /**
     * @param nums: An array of integers
     * @return: An integer
     */
    int maxProduct(vector<int> &nums) {
        // write your code here

        int n = nums.size();

        int ans = nums[0];

        int maxx = 0;
        int minn = 0;
        if(nums[0] > 0)
            maxx = nums[0];
        else
            minn = nums[0];

        for(int i = 1; i < n; ++i)
        {
            if(nums[i] > 0)
            {
                if(maxx != 0)
                    maxx *= nums[i];
                else
                    maxx = nums[i];

                if(minn != 0)
                    minn *= nums[i];
            }
            else if(nums[i] < 0)
            {
                int tmp_minn = 0;
                int tmp_maxx = 0;
                if(maxx != 0)
                    tmp_minn = maxx * nums[i];
                else
                    tmp_minn = nums[i];

                if(minn != 0)
                    tmp_maxx = minn * nums[i];

                maxx = tmp_maxx;
                minn = tmp_minn;
            }
            else
            {
                maxx = 0;
                minn = 0;
            }

            ans = max(ans, maxx);
        }

        return ans;
    }
};