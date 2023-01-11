class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {

        int n = nums.size();
        int cnt = 0;
        int left = -1;
        int ans = 0;

        for(int right = 0; right < n; ++right)
        {
            if(nums[right] == 0)
                ++cnt;
            while(left != right && cnt > k)
            {
                if(nums[++left] == 0)
                    --cnt;
            }
            ans = max(ans, right - left);
        }
        return ans;
    }
};