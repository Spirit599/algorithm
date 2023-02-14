class Solution {
public:
    bool find132pattern(vector<int>& nums) {

        int n = nums.size();
        vector<int> stk({nums.back()});
        int _2nd = INT_MIN;

        for(int i = n - 2; i >= 0; --i)
        {
            if(nums[i] < _2nd)
                return true;

            while(!stk.empty() && nums[i] > stk.back())
            {
                _2nd = max(_2nd, stk.back());
                stk.pop_back();
            }

            stk.push_back(nums[i]);
        }

        return false;
    }
};