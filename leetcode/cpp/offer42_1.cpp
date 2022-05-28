class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        int ans = -0x3f3f3f3f;
        int n = nums.size();
        int cur = 0;
        for (int i = 0; i < n; ++i)
        {
            cur = cur + nums[i];
            ans = max(ans, cur);
            if(cur < 0)
                cur = 0;
        }
        return ans;
    }
};