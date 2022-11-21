class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {

        int n = nums.size();
        int leftIndex = 0;
        int leftMax = nums[0];
        int curMax = nums[0];

        for(int i = 1; i < n; ++i)
        {
            curMax = max(curMax, nums[i]);
            if(leftMax > nums[i])
            {
                leftMax = curMax;
                leftIndex = i;
            }
        }

        return leftIndex + 1;
    }
};