// 1310 · 数组除了自身的乘积

class Solution {
public:
    /**
     * @param nums: an array of integers
     * @return: the product of all the elements of nums except nums[i].
     */
    vector<int> productExceptSelf(vector<int> &nums) {
        
        int n = nums.size();
        vector<int> arr(n, 1);
        int cur = 1;
        for(int i = 1; i < n; ++i)
        {
            cur *= nums[i - 1];
            arr[i] = cur;
        }
        cur = 1;
        for(int i = n - 2; i >= 0; --i)
        {
            cur *= nums[i + 1];
            arr[i] = arr[i] * cur;
        }

        return arr;
    }
};