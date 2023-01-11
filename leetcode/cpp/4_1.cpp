// 4. 寻找两个正序数组的中位数

class Solution {
public:
    int kthInDoubleSortedArrays(vector<int>& nums1, vector<int>& nums2, int k)
    {
        int m = nums1.size();
        int n = nums2.size();
        int index1 = 0;
        int index2 = 0;

        while(1)
        {
            if(index1 == m)
                return nums2[index2 + k - 1];
            if(index2 == n)
                return nums1[index1 + k - 1];
            if(k == 1)
                return min(nums1[index1], nums2[index2]);

            int new_index1 = min(index1 + k / 2 - 1, m - 1);
            int new_index2 = min(index2 + k / 2 - 1, n - 1);
            if(nums1[new_index1] < nums2[new_index2])
            {
                k -= new_index1 - index1 + 1;
                index1 = new_index1 + 1;
            }
            else
            {
                k -= new_index2 - index2 + 1;
                index2 = new_index2 + 1;
            }
        }
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        int length = nums1.size() + nums2.size();
        if(length % 2 == 1)
            return kthInDoubleSortedArrays(nums1, nums2, (length + 1) / 2);
        else
            return (kthInDoubleSortedArrays(nums1, nums2, length / 2) + kthInDoubleSortedArrays(nums1, nums2, length / 2 + 1)) / 2.0;
    }
};