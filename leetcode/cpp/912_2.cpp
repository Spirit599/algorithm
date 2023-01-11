//912. 排序数组
// 归并排序
class Solution {
public:
    int* tmp;
    vector<int> sortArray(vector<int>& nums) {

        int n = nums.size();
        tmp = (int*)malloc(sizeof(int) * n);
        mergeSort(nums, 0, n - 1);

        return nums;
    }

    void mergeSort(vector<int>& nums, int left, int right)
    {
        if(left == right)
            return ;
        int mid = (right - left) / 2 + left;
        mergeSort(nums, left, mid);
        mergeSort(nums, mid + 1, right);

        int i = left;
        int j = mid + 1;
        int index = left;

        while(i <= mid && j <= right)
        {
            if(nums[i] < nums[j])
            {
                tmp[index++] = nums[i++];
            }
            else
            {
                tmp[index++] = nums[j++];
            }
        }

        while(i <= mid)
            tmp[index++] = nums[i++];
        while(j <= right)
            tmp[index++] = nums[j++];

        for(int i = left; i <= right; ++i)
            nums[i] = tmp[i];
    }
    
};