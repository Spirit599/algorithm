//719. 找出第 K 小的数对距离
//二分+双指针
class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {

        sort(nums.begin(), nums.end());

        int low = 0;
        int high = nums.back() - nums.front();

        while(low < high)
        {
            int mid = (high - low) / 2 + low;
            if(check(nums, k, mid))
            {
                high = mid;
            }
            else
            {
                low = mid + 1;
            }
        }

        return low;
    }

    bool check(vector<int>& nums, int k, int mid)
    {
        int n = nums.size();
        int ans = 0;
        for(int i = 0, j = 1; i < n; ++i)
        {
            while(j < n && nums[j] - mid <= nums[i])
                ++j;
            ans += j - i - 1;
            if(ans >= k)
                return true;
        }
        return false;
    }
};