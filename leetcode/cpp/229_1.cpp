// 选举 投票
// 众数

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {

        vector<int> ans;

        int candidate1 = nums[0];
        int candidate2 = nums[0];
        int candidate1_num = 0;
        int candidate2_num = 0;

        
        for(auto i : nums)
        {
            if(i == candidate1)
            {
                ++candidate1_num;
            }
            else if(i == candidate2)
            {
                ++candidate2_num;
            }
            else if(candidate1_num == 0)
            {
                candidate1 = i;
                candidate1_num = 1;
            }
            else if(candidate2_num == 0)
            {
                candidate2 = i;
                candidate2_num = 1;
            }
            else
            {
                --candidate1_num;
                --candidate2_num;
            }
        }

        candidate1_num = 0;
        candidate2_num = 0;
        for(auto i : nums)
        {
            if(i == candidate1)
                ++candidate1_num;
            else if(i == candidate2)
                ++candidate2_num;
        }


        int num = nums.size() / 3;
        if(candidate1_num > num)
            ans.push_back(candidate1);
        if(candidate2_num > num)
            ans.push_back(candidate2);


        return ans;
    }
};