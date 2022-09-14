//912. 排序数组

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {

        srand((unsigned)time(NULL));
    	quick_sort(nums, 0, nums.size() - 1);
    	return nums;
    }
    void quick_sort(vector<int>& nums, int start, int end)
    {
        if(start >= end)
            return;

        int rand_index = rand() % (end - start + 1) + start;
        swap(nums[rand_index], nums[start]);

    	int left = start;
    	int right = end;

        while(left < right)
        {
            while(left < right && nums[right] >= nums[start])
                --right;
            while(left < right && nums[left] < nums[start])
                ++left;
            swap(nums[left], nums[right]);
        }
        swap(nums[left], nums[start]);

        quick_sort(nums, start, left - 1);
        quick_sort(nums, left + 1, end);
    }
};