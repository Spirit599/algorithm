// 滑动窗口

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {

        int ans = 0;
        int right = -1;
        int left = -1;
        int cur = 1;
        int n = nums.size();
        while(right + 1 < n)
        {
            
            if(right == left || cur * nums[right + 1] < k)
            {
                ++right;
                cur *= nums[right];
                if(cur < k)
                    ans += right - left;
                
            }
            else
            {
                ++left;
                cur /= nums[left];
            }
            printf("%d %d\n", cur, ans);
        }

        return ans;
    }
};