// 和的范围覆盖

class Solution {
public:
    int minPatches(vector<int>& nums, int target) {

        long long canRange = 0; //[0, canRange]
        int ans = 0;
        int n = nums.size();
        int i = 0;

        while(canRange < target)
        {
            if(i < n && canRange >= nums[i] - 1)
            {
                canRange += nums[i++];
            }
            else
            {
                canRange = 2 * canRange + 1;
                ++ans;
            }
        }
        return ans;
    }
};