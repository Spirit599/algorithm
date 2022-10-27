// 哈希函数

class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        
        unordered_set<long long> memo;
        int n = nums.size(), mod = 1e9 + 7, power1 = 233, power2 = 2333;
        for(int i = 0; i < n; ++i)
        {
            int cnt = 0;
            int hash1 = 0;
            int hash2 = 0;
            for(int j = i; j < n; ++j)
            {
                if(nums[j] % p == 0)
                    ++cnt;
                if(cnt > k)
                    break;

                hash1 = (1ll * hash1 * power1 + nums[j]) % mod;
                hash2 = (1ll * hash2 * power2 + nums[j]) % mod;
                memo.insert((long long)hash1 << 32 | hash2);
            }
        }
        
        return memo.size();
    }
};