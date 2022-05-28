class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {

        vector<vector<int>> ret;

        sort(nums.begin(), nums.end());

        int nums_size = nums.size();

        int i = 0;
        while(i < nums_size - 3)
        {
            int j = i + 1;
            while(j < nums_size - 2)
            {
                int k = j + 1;
                int l = nums_size - 1;
                while(k < l)
                {
                    long long sum = (long long)nums[i] + nums[j] + nums[k] + nums[l];
                    if(sum < target)
                        ++k;
                    else if(sum > target)
                        --l;
                    else
                    {
                        ret.push_back({nums[i],nums[j],nums[k],nums[l]});
                        ++k;
                        while(k < l && nums[k] == nums[k - 1])
                            ++k;
                        --l;
                        while(k < l && nums[l] == nums[l + 1])
                            --l;
                    }
                }
                ++j;
                while(j < nums_size - 2 && nums[j] == nums[j - 1])
                    ++j;
            }
            ++i;
            while(i < nums_size - 3 && nums[i] == nums[i - 1])
                ++i;
        }

        return ret;
    }
};