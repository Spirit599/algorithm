class Solution {
public:
    int robhelp(vector<int> nums) {

        int yes = nums[0];
        int no = 0;
        int n = nums.size();
        for(int i = 1; i < n; ++i)
        {
            int nyes = max(yes, no + nums[i]);
            int nno = yes;
            yes = nyes;
            no = nno;
        }
        return max(yes, no);
    }
    int rob(vector<int>& nums) {

        if(nums.size() == 1)
            return nums[0];
        return max(robhelp(vector<int>(nums.begin(), nums.end() - 1)), 
                    robhelp(vector<int>(nums.begin() + 1, nums.end())));
    }
};