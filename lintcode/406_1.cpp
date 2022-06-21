// 406 · 和大于S的最小子数组

class Solution {
public:
    /**
     * @param nums: an array of integers
     * @param s: An integer
     * @return: an integer representing the minimum size of subarray
     */
    int minimumSize(vector<int> &nums, int s) {
        
        int n = nums.size();

        if(n == 0)
            return -1;

        int left = -1;
        int right = -1;
        int cur = 0;
        int ans = 0x7fffffff;

        while(right < n)
        {
            if(cur < s)
            {
                ++right;
                cur += nums[right];
            }
            else
            {
                ans = min(ans ,right - left);
                ++left;
                cur -= nums[left];
            }
        }

        if(ans != 0x7fffffff)
            return ans;
        else
            return -1;
    }
};