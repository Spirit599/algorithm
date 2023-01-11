class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        
        sort(nums.begin(), nums.end());
        int start = nums[0];
        int ans = 1;
        int n = nums.size();

        for(int i = 1; i < n; ++i)
        {
            if(start + k < nums[i])
            {
                ++ans;
                start = nums[i];
            }
        }

        return ans;

    }
};