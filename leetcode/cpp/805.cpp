class Solution {
public:
    bool splitArraySameAverage(vector<int>& nums) {
        
        int allSum = accumulate(nums.begin(), nums.end(), 0);
        int n = nums.size();
        if(n == 1)
            return false;

        bool dp[n + 1][allSum + 1];
        memset(dp, 0, sizeof(dp));
        dp[0][0] = true;

        for(int i = 0; i < n; ++i)
        {
            for(int k = n - 2; k >= 0; --k)
            {
                for(int j = allSum; j >= 0; --j)
                {
                    if(dp[k][j] && j + nums[i] <= allSum)
                    {
                        int cnt = k + 1;
                        int sum = j + nums[i];
                        if(cnt * (allSum - sum) == (n - cnt) * sum)
                            return true;
                        
                        dp[k + 1][j + nums[i]] = true;
                    }
                }
            }
        }

        return false;
    }
};