class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {

        int maxx = nums[0];
        int curMax = 0;
        int minn = nums[0];
        int curMin = 0;
        int sum = 0;
        int n = nums.size();

        for(int i = 0; i < n; ++i)
        {
            curMax += nums[i];
            maxx = max(maxx, curMax);
            if(curMax < 0)
                curMax = 0;

            curMin += nums[i];
            minn = min(minn, curMin);
            if(curMin > 0)
                curMin = 0;

            sum += nums[i];
        }

        if(minn != sum)
            return max(maxx, sum - minn);
        else
            return maxx;
    }
};