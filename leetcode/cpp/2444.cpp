class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        
        long long ans = 0;
        int maxIndex = -1;
        int minIndex = -1;
        int refuseIndex = -1;
        int n = nums.size();
        for(int i = 0; i < n; ++i)
        {
            int num = nums[i];
            if(num == minK)
                minIndex = i;
            if(num == maxK)
                maxIndex = i;
            if(num > maxK || num < minK)
                refuseIndex = i;
            ans += max(min(maxIndex, minIndex) - refuseIndex, 0);
        }
        return ans;
    }
};