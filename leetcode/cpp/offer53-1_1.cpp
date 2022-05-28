//二分

class Solution {
public:
    int search(vector<int>& nums, int target) {

        int high = nums.size() - 1;
        int low = 0;

        // if(high == -1)
        //     return 0;

        int low_index = -1;
        while(low <= high)
        {
            int mid = (high - low) / 2 + low;
            if(nums[mid] == target)
            {
                //++ans;
                low_index = mid;
                high = mid - 1;
            }
            else if(nums[mid] > target)
            {
                high = mid - 1;
            }
            else if(nums[mid] < target)
            {
                low = mid + 1;
            }
            //cout<<low<<" "<<mid<<" "<<high<<endl;
        }

        high = nums.size() - 1;
        low = 0;
        int high_index = -2;
        while(low <= high)
        {
            int mid = (high - low + 1) / 2 + low;
            if(nums[mid] == target)
            {
                //++ans;
                high_index = mid;
                low = mid + 1;
            }
            else if(nums[mid] > target)
            {
                high = mid - 1;
            }
            else if(nums[mid] < target)
            {
                low = mid + 1;
            }
            //cout<<low<<" "<<mid<<" "<<high<<endl;
        }
        // if(high_index == -1)
        //     return 0;
        return high_index - low_index + 1;
    }
};