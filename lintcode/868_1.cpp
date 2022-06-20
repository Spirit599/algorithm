// 868 · 子数组的最大平均值 I

#include <numeric>

class Solution {
public:
    /**
     * @param nums: an array
     * @param k: an integer
     * @return: the maximum average value
     */
    double findMaxAverage(vector<int> &nums, int k) {

        int n = nums.size();
        if(n <= k)
            return accumulate(nums.begin(), nums.end(), 0) / (double)k;
        
        int sum = accumulate(nums.begin(), nums.begin() + k, 0);
        int ans = sum;

        int left = 0;
        int right = k - 1;
        while(++right < n)
        {
            sum += nums[right];
            sum -= nums[left++];
            ans = max(ans, sum);
        }

        return ans / (double)k;
    }
};