class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {

        int n = nums.size();
        
        int ll = -1;
        int rr = -1;
        int ans = 0;
        for(int i = 0; i < n; ++i)
        {
            if(left <= nums[i] && nums[i] <= right)
            {
                rr = i;
            }
            else if(nums[i] > right)
            {
                ll = i;
                rr = i;
            }
            ans += (rr - ll);
        }
        return ans;

    }
};