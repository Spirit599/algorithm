//状态 动态规划
// 801. 使序列递增的最小交换次数
class Solution {
public:
    int minSwap(vector<int>& nums1, vector<int>& nums2) {

        int a = 0;
        int b = 1;

        int n = nums2.size();
        for(int i = 1; i < n; ++i)
        {
            int na = INT_MAX;
            int nb = INT_MAX;
            if(nums1[i] > nums1[i - 1] && nums2[i] > nums2[i - 1])
            {
                na = min(na, a);
                nb = min(nb, b + 1);
            }
            if(nums1[i] > nums2[i - 1] && nums2[i] > nums1[i - 1])
            {
                na = min(na, b);
                nb = min(nb, a + 1);
            }
            a = na;
            b = nb;
        }

        return min(a, b);
    }
};