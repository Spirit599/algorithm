class Solution {
public:
    bool isStraight(vector<int>& nums) {

        sort(nums.begin(), nums.end());

        int kings = 0;
        int n = nums.size();
        int i = 0;
        for (; i < n; ++i)
        {
            if(nums[i] == 0)
            {
                ++kings;
            }
            else
            {
                break;
            }
        }
        //cout<<i<<endl;
        for (; i < n - 1; ++i)
        {
            if(nums[i] == nums[i + 1])
                return false;
            kings -= (nums[i + 1] - nums[i] - 1);
            if(kings < 0)
                return false;
        }

        return true;

    }
};