class Solution {
public:
    int maximumTop(vector<int>& nums, int k) {
        
        int nums_size = nums.size();

        if(nums_size == 1 && (k & 1))
            return -1;
        else if(nums_size == 1 && !(k & 1))
            return nums[0];


        if(k >= nums_size + 1)
            return *max_element(nums.begin(), nums.end());
        else if(k == nums_size)
            return *max_element(nums.begin(), nums.begin() + k - 1);
        else if(k == 1)
            return nums[1];
        else if(k == 0)
            return nums[0];


        int maxx = *max_element(nums.begin(), nums.begin() + k - 1);
        maxx = max(maxx, nums[k]);

        return maxx;
    }
};