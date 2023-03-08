class Solution {
public:
    int maxNumOfMarkedIndices(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int high = n / 2;
        int low = 0;

        auto check = [&](int mid) -> bool {

            int ll = 0;
            int rr = n - mid;
            while(mid--)
            {
                if(nums[ll++] * 2 > nums[rr++])
                    return false;
            }
            return true;
        };

        while(low != high)
        {
            int mid = (low + high + 1) >> 1;
            if(check(mid))
                low = mid;
            else
                high = mid - 1;
        }



        return 2 * low;
    }
};