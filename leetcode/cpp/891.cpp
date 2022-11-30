// 这是子数组

class Solution {
public:
    int sumSubseqWidths(vector<int>& nums) {

        int n = nums.size();
        int maxxLeft[n];
        memset(maxxLeft, -1, sizeof(maxxLeft));
        int minnLeft[n];
        memset(minnLeft, -1, sizeof(minnLeft));

        int maxxRight[n];
        int minnRight[n];
        for(int i = 0; i < n; ++i)
        {
            maxxRight[i] = n;
            minnRight[i] = n;
        }

        vector<int> upStk;
        vector<int> downStk;
        for(int i = 0; i < n; ++i)
        {
            while(!upStk.empty() && nums[upStk.back()] >= nums[i])
            {
                minnRight[upStk.back()] = i;
                upStk.pop_back();
            }
            if(!upStk.empty())
                minnLeft[i] = upStk.back();
            upStk.push_back(i);

            while(!downStk.empty() && nums[downStk.back()] <= nums[i])
            {
                maxxRight[downStk.back()] = i;
                downStk.pop_back();
            }
            if(!downStk.empty())
                maxxLeft[i] = downStk.back();
            downStk.push_back(i);
        }

        long long ans = 0;
        int MOD = 1e9 + 7;
        for(int i = 0; i < n; ++i)
        {
            long long maxxLen = (maxxRight[i] - i) * (i - maxxLeft[i]);
            long long minnLen = (minnRight[i] - i) * (i - minnLeft[i]);

            printf("%d %d\n", minnLeft[i], minnRight[i]);
            ans += nums[i] * (maxxLen - minnLen);
            ans %= MOD;

        }

        return (ans + MOD) % MOD;

    }
};