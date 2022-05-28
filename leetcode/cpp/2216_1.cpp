//贪心

class Solution {
public:
    int minDeletion(vector<int>& nums) {
        
        int cnt = 0;
        int ans = 0;
        int pre = -1;

        for (int i = 0; i < nums.size(); ++i)
        {
            if((cnt & 1) == 0)
            {
                ++cnt;
                pre = nums[i];
            }
            else
            {
                if(nums[i] == pre)
                {
                    ++ans;
                }
                else
                {
                    ++cnt;
                }
            }
        }


        if((cnt & 1))
            ++ans;
        return ans;
    }
};