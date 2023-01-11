class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        sort(nums.begin(), nums.end());

        int n = nums.size();
        vector<vector<int>> ans;

        int i = 0;
        while(i < n)
        {
            int j = i + 1;
            int k = n - 1;
            while(j < k)
            {
                //printf("%d %d %d\n", i,j,k);
                int num = nums[i] + nums[j] + nums[k];
                if(num > 0)
                {
                    --k;
                    // while(j < k && nums[k] == nums[k + 1])
                    //     --k;
                }
                else if(num < 0)
                {
                    ++j;
                    // while(j < k && nums[j] == nums[j - 1])
                    //     ++j;
                }
                else
                {
                    ans.push_back({nums[i], nums[j], nums[k]});
                    ++j;
                    while(j < k && nums[j] == nums[j - 1])
                        ++j;
                }
            }
            ++i;
            while(i < n && nums[i] == nums[i - 1])
                ++i;
        }


        return ans;
    }
};