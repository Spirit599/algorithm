class Solution {
public:
    long long minOperations(vector<int>& nums1, vector<int>& nums2, int k) {
        
        if(k == 0)
            return nums1 == nums2 ? 0 : -1;
        long long ans = 0;
        long long sum = 0;
        int n = nums1.size();
        for(int i = 0; i < n; ++i)
        {
            int val = nums1[i] - nums2[i];
            sum += val;
            if(val % k != 0)
                return -1;
            if(val > 0)
                ans += val / k;
        }

        if(sum == 0)
            return ans;
        else
            return -1;
    }
};