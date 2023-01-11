// 33. 搜索旋转排序数组

class Solution {
public:
    int search(vector<int>& nums, int target) {


    	int low = 0;
        int n = nums.size();
        int high = nums.size() - 1;

        while(low <= high)
        {
            int mid = (low + high) >> 1;
            printf("%d %d \n", low, high);
            if(nums[mid] == target)
                return mid;

            if(nums[0] <= nums[mid])
            {
                if(nums[0] <= target && target < nums[mid])
                    high = mid - 1;
                else
                    low = mid + 1;
            }
            else
            {
                if(nums[mid] < target && target <= nums[n - 1])
                    low = mid + 1;
                else
                    high = mid - 1;
            }
        }

    	return -1;
    }
};