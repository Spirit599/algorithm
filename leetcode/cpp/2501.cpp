class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        
        int n = nums.size();
        unordered_map<long long, int> memo;

        sort(nums.begin(), nums.end(), greater<int>());

        int ans = -1;
        for(int i = 0; i < n; ++i)
        {
            auto it = memo.find(1ll * nums[i] * nums[i]);
            if(it != memo.end())
            {
                memo[nums[i]] = it->second + 1;
                ans = max(ans, it->second + 1);
            }
            else
            {
                memo[nums[i]] = 1;
            }
        }

        return ans;
    }
};