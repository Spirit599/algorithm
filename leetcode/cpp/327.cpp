// 分治
// 归并排序 前缀和

class Solution {
public:
    int lower;
    int upper;
    long long *tmp = nullptr;
    int countRangeSum(vector<int>& nums, int lower, int upper) {

        this->lower = lower;
        this->upper = upper;
        int n = nums.size() + 1;
        tmp = (long long*)malloc(sizeof(long long) * n);
        long long preSum[n];
        preSum[0] = 0;
        for(int i = 1; i < n; ++i)
            preSum[i] = preSum[i - 1] + nums[i - 1];

        return partiton(preSum, 0, n - 1);
    }
    int partiton(long long nums[], int left, int right)
    {
        if(left == right)
            return 0;

        int mid = (left + right) >> 1;
        int ret = partiton(nums, left, mid);
        ret += partiton(nums, mid + 1, right);

        int ll = mid + 1;
        int rr = mid + 1;
        for(int i = left; i <= mid; ++i)
        {
            while(rr <= right && nums[rr] <= nums[i] + upper)
                ++rr;
            while(ll <= right && nums[ll] < nums[i] + lower)
                ++ll;
            ret += rr - ll;
        }

        int i = left;
        int j = mid + 1;
        int k = left;
        while(i <= mid && j <= right)
        {
            if(nums[i] < nums[j])
                tmp[k++] = nums[i++];
            else
                tmp[k++] = nums[j++];
        }
        while(i <= mid)
            tmp[k++] = nums[i++];
        while(j <= right)
            tmp[k++] = nums[j++];
        for(int i = left; i <= right; ++i)
            nums[i] = tmp[i];

        return ret;
    }
};