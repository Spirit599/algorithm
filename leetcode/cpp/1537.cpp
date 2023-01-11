class Solution {
public:
    int maxSum(vector<int>& nums1, vector<int>& nums2) {

        vector<long long> arr1;
        vector<long long> arr2;
        int ptr1 = 0;
        int ptr2 = 0;
        long long sum1 = 0;
        long long sum2 = 0;
        int n1 = nums1.size();
        int n2 = nums2.size();
        int mod = 1e9 + 7;
        int ans = 0;
        
        while(ptr1 < n1 && ptr2 < n2)
        {
            if(nums1[ptr1] < nums2[ptr2])
            {
                sum1 += nums1[ptr1++];
            }
            else if(nums1[ptr1] > nums2[ptr2])
            {
                sum2 += nums2[ptr2++];
            }
            else
            {
                sum1 += nums1[ptr1++];
                sum2 += nums2[ptr2++];
                ans = (ans + max(sum1, sum2)) % mod;
                sum1 = 0;
                sum2 = 0;
            }
        }
        while(ptr1 < n1)
        {
            sum1 += nums1[ptr1++];
        }
        while(ptr2 < n2)
        {
            sum2 += nums2[ptr2++];
        }

        ans = (ans + max(sum1, sum2)) % mod;
        return ans;
    }
};