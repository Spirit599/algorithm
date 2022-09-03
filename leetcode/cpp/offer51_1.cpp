// 剑指 Offer 51. 数组中的逆序对
// 归并排序
class Solution {
public:
    int* tmp = nullptr;
    int reversePairs(vector<int>& nums) {

        int n = nums.size();
        if(n == 0)
            return 0;


        tmp = (int*)malloc(sizeof(int) * n);
        int ans = mergeSort(nums, 0, n - 1);

        return ans;
    }

    int mergeSort(vector<int>& nums, int low, int high)
    {
        if(low == high)
            return 0;

        int mid = (high - low) / 2 + low;
        int ret = 0;
        ret += mergeSort(nums, low, mid);
        ret += mergeSort(nums, mid + 1, high);

        int i = low;
        int j = mid + 1;
        int k = low;
        while(i <= mid && j <= high)
        {
            if(nums[i] <= nums[j])
                tmp[k++] = nums[i++];
            else
            {
                ret += (mid - i + 1);
                tmp[k++] = nums[j++];
            }
        }

        while(i <= mid)
            tmp[k++] = nums[i++];
        while(j <= high)
        {
            ret += (mid - i + 1);
            tmp[k++] = nums[j++];
        }

        for(int l = low; l <= high; ++l)
            nums[l] = tmp[l];

        return ret;
    }
};