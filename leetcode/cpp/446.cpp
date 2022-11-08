// 等差数列

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {

        int n = nums.size();
        unordered_map<long long, int> dp[n];
        unordered_map<long long, int> wait[n];

        int ans = 0;
        for(int i = 0; i < n; ++i)
        {
            // dp[i][0] = 1;
            for(int j = 0; j < i; ++j)
            {
                long long dif = 1ll * nums[i] - nums[j];
                ++wait[i][dif];

                int ret = 0;
                auto it = wait[j].find(dif);
                if(it != wait[j].end())
                    ret += it->second;
                it = dp[j].find(dif);
                if(it != dp[j].end())
                    ret += it->second;
                if(ret != 0)
                {
                    ans += ret;
                    dp[i][dif] += ret;
                }
            }
        }
        return ans;

    }
};