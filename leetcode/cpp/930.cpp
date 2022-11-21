class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {

        int ans = 0;
        int n = nums.size();
        int cur = 0;
        int left = -1;
        int len = 0;

        for(int right = 0; right < n; ++right)
        {
            cur += nums[right];
            while(left != right && cur > goal)
            {
                len = 0;
                cur -= nums[++left];
            }

            if(cur != goal || left == right)
                continue;

            while(left + 1 < right && nums[left + 1] == 0)
            {
                ++left;
                ++len;
            }

            ans += (len + 1);
        }

        return ans;
    }
};