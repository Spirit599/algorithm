class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {


        sort(nums.begin(), nums.end());

        int i = 0;
        int ret = 0;
        int min_detal = 2147483647;
        int nums_length = nums.size();
        
        while(i < nums_length - 2)
        {
            int j = i + 1;
            int k = nums_length - 1;

            while(j != k)
            {   //cout<<i<<j<<k<<endl;
                int my_target = nums[i] + nums[j] + nums[k] - target;   
                int detal = (my_target > 0) ? my_target : - my_target;
                if(detal < min_detal)
                {
                    ret = my_target + target;
                    min_detal = detal;
                }
                if(my_target > 0)
                {
                    k--;
                    // while(j != k && nums[k] == nums[k + 1])
                    // {
                    //     k--;
                    // }
                }
                else if(my_target < 0)
                {
                    j++;
                    // while(j != k && nums[j] == nums[j - 1])
                    // {
                    //     j++;
                    // }
                }
                else
                {
                    
                    return target;
                }

            }
            i++;
            // while(i < nums_length - 2 && nums[i] == nums[i - 1])
            // {
            //      i++;
            // }
        }

        return ret;
    }
};