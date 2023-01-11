// 这是才是子序列

int MOD = 1e9 + 7;
class Solution {
public:
    int sumSubseqWidths(vector<int>& nums) {

        int n = nums.size();
        sort(nums.begin(), nums.end(), greater<int>());

        int dp[n];
        dp[0] = 1;
        for(int i = 1; i < n; ++i)
            dp[i] = dp[i - 1] * 2 % MOD;

        long long ans = 0;
        

        for(int i = 0; i < n; ++i)
        {
            ans += 1ll * (dp[n - i - 1] - dp[i]) * nums[i];
            ans %= MOD;
        }

        return (ans + MOD) % MOD;

    }
};