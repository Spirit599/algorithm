class Solution {
public:
    int *tmp = nullptr;
    int reversePairs(vector<int>& nums) {

        int n = nums.size();
        tmp = (int*)malloc(sizeof(int) * n);
        return partiton(nums, 0, n - 1);
    }

    int partiton(vector<int>& nums, int left, int right)
    {
        if(left == right)
            return 0;

        int mid = (left + right) >> 1;
        int ret = partiton(nums, left, mid);
        ret += partiton(nums, mid + 1, right);

        int j = mid + 1;
        for(int i = left; i <= mid; ++i)
        {
            while(j <= right && 1ll * nums[j] * 2 < 1ll * nums[i])
                ++j;
            ret +=  j - mid - 1;
        }

        int i = left;
        j = mid + 1;
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