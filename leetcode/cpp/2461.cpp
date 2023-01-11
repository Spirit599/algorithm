class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        
        int n = nums.size();
        long long preSum[n + 1];
        preSum[0] = 0;

        for(int i = 0; i < n; ++i)
            preSum[i + 1] = preSum[i] + nums[i];

        unordered_set<int> vis;
        long long ans = 0;
        int i = 0;

        while(i + k <= n)
        {

            // printf("i = %d\n", i);
            int len = 0;
            int oi = i;
            while(len < k)
            {
                if(vis.find(nums[i + len]) != vis.end())
                    break;
                vis.insert(nums[i + len]);
                ++len;
            }
            i = i + len;

            if(len == k)
            {
                ans = max(ans, preSum[i] - preSum[i - k]);
                while(i < n)
                {
                    vis.erase(nums[i - k]);
                    if(vis.find(nums[i]) != vis.end())
                    {
                        for(int j = i - k + 1; j < i; ++j)
                            vis.erase(nums[j]);
                        break;
                    }
                    else
                    {
                        vis.insert(nums[i]);
                        ++i;
                        ans = max(ans, preSum[i] - preSum[i - k]);
                    }
                }
            }
            else
            {
                for(int j = oi; j < i; ++j)
                    vis.erase(nums[j]);
            }

        }

        return ans;
    }
};