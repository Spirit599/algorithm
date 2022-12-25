class Solution {
public:
    int minOperations(vector<int>& nums) {

        sort(nums.begin(), nums.end());
        int n = nums.size();
        nums.erase(unique(nums.begin(), nums.end()), nums.end());
        int nn = nums.size();
        int ans = INT_MAX;

        int right = 0;
        for(int left = 0; left < nn; ++left)
        {
            while(right < nn && nums[right] <= nums[left] + n - 1)
                ++right;
            ans = min(ans, n - (right - left));
        }
        return ans;
    }
};