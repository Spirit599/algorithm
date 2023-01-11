// 698. 划分为k个相等的子集
//状态压缩

class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {

        int allSum = accumulate(nums.begin(), nums.end(), 0);
        if(allSum % k)
            return false;
        int part = allSum / k;
        sort(nums.begin(), nums.end());

        int n = nums.size();
        bool dp[1 << n];
        int sum[1 << n];
        memset(dp, 0, sizeof(dp));
        memset(sum, 0, sizeof(sum));

        dp[0] = true;
        for(int i = 0; i < (1 << n); ++i)
        {
            if(dp[i] == false)
                continue;

            for(int j = 0; j < n; ++j)
            {
                if(sum[i] + nums[j] > part)
                    break;
                if(((i >> j) & 1) == 0)
                {
                    int next = i | (1 << j);
                    if(!dp[next])
                    {
                        sum[next] = (sum[i] + nums[j]) % part;
                        dp[next] = true;
                    }
                }
            }
        }

        return dp[(1 << n) - 1];
    }
};