class Solution {
public:
    /**
     * @param nums: An integer array
     * @return: The second max number in the array.
     */
    int secondMax(vector<int> &nums) {
        
        int max1 = max(nums[0], nums[1]);
        int max2 = min(nums[0], nums[1]);

        int n = nums.size();
        for(int i = 2; i < n; ++i)
        {
            if(nums[i] > max1)
            {
                max2 = max1;
                max1 = nums[i];
            }
            else if(nums[i] > max2)
            {
                max2 = nums[i];
            }
        }

        return max2;
    }
};