class Solution {
public:
    bool isIdealPermutation(vector<int>& nums) {

        int n = nums.size();
        int maxx = nums[0];
        for(int i = 2; i < n; ++i)
        {
            if(nums[i] < maxx)
                return false;
            maxx = max(maxx, nums[i - 1]);
        }
        return true;
    }
};