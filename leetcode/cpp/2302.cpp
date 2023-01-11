class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        
        int n = nums.size();
        int left = -1;
        long long leftSum = 0;
        long long rightSum = 0;
        long long ans = 0;
        for(int i = 0; i < n; ++i)
        {
            rightSum += nums[i];
            while(1)
            {
                int tmp = (rightSum - leftSum) * (i - left);
                if(tmp < k)
                    break;
                ++left;
                leftSum += nums[left];
            }
            ans += i - left;
        }
        return ans;
    }
};