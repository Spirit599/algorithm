class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {

        
        int n = arr.size();
        int ans = 0;
        int memo[target + 1];
        memset(memo, 0, sizeof(memo));
        const int MOD = 1e9 + 7;

        for(int i = 1; i < n; ++i)
        {
            int twoSum = target - arr[i];
            if(twoSum >= 0)
            {
                ans += memo[twoSum];
                ans %= MOD;
            }
            for(int j = 0; j < i; ++j)
            {
                if(arr[i] + arr[j] <= target)
                    ++memo[arr[i] + arr[j]];
            }
        }

        return ans;
    }
};