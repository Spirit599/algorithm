class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        vector<vector<int>> ret;

        int nums_length = nums.size();
        if(nums_length < 3)
            return ret;

        sort(nums.begin(), nums.end());

        int i = 0;
        while(i < nums_length - 2)
        {
            int j = i + 1;
            int k = nums_length - 1;

            while(j != k)
            {   //cout<<i<<j<<k<<endl;
                int target = nums[i] + nums[j] + nums[k];   

                if(target > 0)
                {
                    k--;
                    // while(j != k && nums[k] == nums[k + 1])
                    // {
                    //     k--;
                    // }
                }
                else if(target < 0)
                {
                    j++;
                    // while(j != k && nums[j] == nums[j - 1])
                    // {
                    //     j++;
                    // }
                }
                else
                {
                    ret.push_back({nums[i], nums[j], nums[k]});
                    j++;
                    while(j != k && nums[j] == nums[j - 1])
                    {
                        j++;
                    }
                }

            }
            i++;
            while(i < nums_length - 2 && nums[i] == nums[i - 1])
            {
                 i++;
            }
        }

        return ret;

    }
};