// 33. 搜索旋转排序数组

class Solution {
public:
    int search(vector<int>& nums, int target) {


    	int left = 0;
    	int n = nums.size();
    	int right = n - 1;

    	while(left <= right)
    	{
    		int mid = (right - left) / 2 + left;
    		if(nums[mid] == target)
    			return mid;

    		if(nums[0] <= nums[mid])
    		{
    			if(nums[0] <= target && target < nums[mid])
    			{
    				right = mid - 1;
    			}
    			else
    			{
    				left = mid + 1;
    			}
    		}
    		else
    		{
    			if(nums[mid] < target && target <= nums[n - 1])
    			{
    				left = mid + 1;
    			}
    			else
    			{
    				right = mid - 1;
    			}
    		}
    	}

    	return -1;
    }
};