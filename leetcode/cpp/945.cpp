class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {

        sort(nums.begin(), nums.end());
        bool memo[200005];
        memset(memo, 0, sizeof(memo));

        int ptr = 0;
        int ans = 0;
        for(int num : nums)
        {
            if(!memo[num])
            {
                memo[num] = true;
            }
            else
            {
                ptr = max(ptr, num);
                while(memo[ptr])
                    ++ptr;
                ans += ptr - num;
                memo[ptr] = true;
            }
        }
        return ans;
    }
};