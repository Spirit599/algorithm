// 三进制 状态压缩

class Solution {
public:
    int maximumANDSum(vector<int>& nums, int numSlots) {
        
        int S = pow(3, numSlots);
        int dp[S];
        memset(dp, 0, sizeof(dp));
        int n = nums.size();

        for(int s = 1; s < S; ++s)
        {
            int w = 0;
            for(int i = 0, mask = s; i < numSlots; ++i, mask /= 3)
            {
                w += mask % 3;
            }
            if(w > n)
                continue;
            for(int i = 0, mask = s, k = 1; i < numSlots; ++i, mask /= 3, k *= 3)
            {
                int has = mask % 3;
                if(has)
                    dp[s] = max(dp[s], dp[s - k] + (nums[w - 1] & (i + 1)));
            }
        }

        return *max_element(dp, dp + S);
    }
};