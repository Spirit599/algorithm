class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {

        int left = 0;
        int right = nums.size() - 1;

        while(left < right)
        {
            while(left < right && !(nums[left] & 1))
                ++left;
            while(left < right && (nums[right] & 1))
                --right;

            //printf("%d %d\n", left, right);

            swap(nums[left], nums[right]);
            ++left;
            --right;
        }

        return nums;
    }
};