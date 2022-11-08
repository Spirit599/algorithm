class Solution {
public:
    int minMoves2(vector<int>& nums) {

        sort(nums.begin(), nums.end());
        int n = nums.size();
        int avg1 = nums[n / 2];
        int ans1 = 0;
        for(int num : nums)
        {
            ans1 += abs(num - avg1);
        }
        return ans1;
    }
};