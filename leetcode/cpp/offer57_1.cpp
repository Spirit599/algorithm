class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        int start = 0;
        int end = nums.size() - 1;

        while(start != end)
        {
            int sum = nums[start] + nums[end];
            if(sum < target)
                ++start;
            else if(sum > target)
                --end;
            else
                return {nums[start], nums[end]};
        }
        return {};
    }
};