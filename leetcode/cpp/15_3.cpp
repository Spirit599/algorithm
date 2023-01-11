class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        sort(nums.begin(), nums.end());

        int n = nums.size();
        vector<vector<int>> ans;

        int i = 0;
        while(i + 2 < n)
        {
            int j = i + 1;
            int k = n - 1;
            while(j < k)
            {
                int sum = nums[i] + nums[j] + nums[k];
                if(sum > 0)
                    --k;
                else if(sum < 0)
                    ++j;
                else
                {
                    ans.push_back({nums[i], nums[j], nums[k]});
                    
                    ++j;
                    while(j < n - 1 && nums[j] == nums[j - 1])
                        ++j;

                    --k;
                }
            }
            ++i;
            while(i < n - 2 && nums[i] == nums[i - 1])
                ++i;
        }
        return ans;
    }
};