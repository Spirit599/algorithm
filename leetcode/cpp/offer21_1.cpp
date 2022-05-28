class Solution {
public:
    vector<int> exchange(vector<int>& nums) {

        int start = 0;
        int end = nums.size() - 1;
        while(start < end)
        {
            while((nums[start] & 1) && start < end)
                ++start;
            while(!(nums[end] & 1) && start < end)
                --end;
            swap(nums[start], nums[end]);
            ++start;--end;
        }
        return nums;
    }
};