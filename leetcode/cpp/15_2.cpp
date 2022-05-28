class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        vector<vector<int>> ret;

        sort(nums.begin(), nums.end());

        int nums_size = nums.size();

        int i = 0;
        while(i < nums_size - 2)
        {

            int j = i + 1;
            int k = nums_size - 1;
            while(j < k)
            {
                //cout<<i<<j<<k<<endl;
                int sum = nums[i] + nums[j] + nums[k];
                if(sum < 0)
                {
                    j++;
                }
                else if(sum > 0)
                {
                    k--;
                }
                else
                {
                    ret.push_back({nums[i],nums[j],nums[k]});

                    ++j;
                    while(j < nums_size - 1 && nums[j] == nums[j - 1])
                        ++j;

                    --k;
                    while(k >= 2 && nums[k] == nums[k + 1])
                        --k;
                }
            }

            ++i;
            while(i < nums_size - 2 && nums[i] == nums[i - 1])
                ++i;
        }

        return ret;
    }
};