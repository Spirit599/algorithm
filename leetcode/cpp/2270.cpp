class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        
        long long allSum = 0;
        for(int num : nums)
            allSum += num;
        int n = nums.size();
        long long curSum = 0;
        int ans = 0;
        for(int i = 0; i < n - 1; ++i)
        {
            curSum += nums[i];
            if(curSum >= allSum - curSum)
                ++ans;
        }
        return ans;
    }
};