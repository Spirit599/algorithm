class Solution {
public:
    int findKthSortedArrays(vector<int>& nums1, vector<int>& nums2, int k) {

        int n1 = nums1.size();
        int n2 = nums2.size();
        int idx1 = 0;
        int idx2 = 0;

        while(1)
        {
            if(n1 == idx1)
                return nums2[idx2 + k - 1];
            if(n2 == idx2)
                return nums1[idx1 + k - 1];
            if(k == 1)
                return min(nums1[idx1], nums2[idx2]);

            int nidx1 = min(idx1 + k / 2 - 1, n1 - 1);
            int nidx2 = min(idx2 + k / 2 - 1, n2 - 1);
            if(nums1[nidx1] < nums2[nidx2])
            {
                k -= nidx1 - idx1 + 1;
                idx1 = nidx1 + 1;
            }
            else
            {
                k -= nidx2 - idx2 + 1;
                idx2 = nidx2 + 1;
            }
        }
        return -1;
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        int sum = nums1.size();
        sum += nums2.size();
        if(sum & 1)
            return findKthSortedArrays(nums1, nums2, sum / 2 + 1);
        else
            return (findKthSortedArrays(nums1, nums2, sum / 2) + findKthSortedArrays(nums1, nums2, sum / 2 + 1)) / 2.0;
    }
};