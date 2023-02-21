class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {

        int ans = 0;
        map<int, int> memo;
        int n = nums.size();

        int left = 0;
        for(int right = 0; right < n; ++right)
        {
            ++memo[nums[right]];
            while(memo.rbegin()->first > memo.begin()->first + limit)
            {
                if(--memo[nums[left]] == 0)
                    memo.erase(nums[left]);
                ++left;
            }
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};