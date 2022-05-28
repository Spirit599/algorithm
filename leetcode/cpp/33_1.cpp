class Solution {
public:
    int search(vector<int>& nums, int target) {

        int low = 0;
        int up = nums.size() - 1;
        int high = up;
        int mid =(high - low) / 2 + low;

        while(low <= high)
        {
            cout<<low<<high<<endl;
            mid =(high - low) / 2 + low;
            if(nums[mid] == target)
                return mid;
            else
            {
                if(nums[0] < nums[mid])
                {
                    if(nums[0] <= target && target < nums[mid])
                    {
                        high = mid - 1;
                    }
                    else
                    {
                        low = mid + 1;
                    }
                }
                else
                {
                    if(nums[mid] < target && target <= nums[up])
                    {
                        low = mid + 1;
                    }
                    else
                    {
                        high = mid - 1; 
                    }
                }
            }
        }

        return -1;
    }
};