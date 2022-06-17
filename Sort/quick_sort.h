void quick_sort(vector<int>& arr, int start, int end)
{
    if(start >= end)
        return ;
    int left = start;
    int right = end;

    int rand_index = rand() % (end - start + 1) + start;
    swap(arr[rand_index], arr[start]);

    while(left < right)
    {
        while(left < right && arr[right] >= arr[start])
            --right;
        while(left < right && arr[left] <= arr[start])
            ++left;
        swap(arr[left], arr[right]);
    }
    swap(arr[left], arr[start]);

    quick_sort(arr, start, left - 1);
    quick_sort(arr, left + 1, end);

    return ;
}




int findKthLargest(vector<int>& nums, int k) 
{
    int start = 0;
    int end = nums.size() - 1;

    while(1)
    {
        int index = partition(nums, start, end);
        if(index == k - 1)
            return nums[index];
        else if(index < k - 1)
            start = index + 1;
        else
            end = index - 1;
    }
}

int partition(vector<int>& arr, int start, int end)
{
    int left = start;
    int right = end;

    int rand_index = rand() % (end - start + 1) + start;
    swap(arr[rand_index], arr[start]);


    while(left < right)
    {
        while(left < right && arr[right] <= arr[start])
            --right;
        while(left < right && arr[left] >= arr[start])
            ++left;
        swap(arr[left], arr[right]);
    }

    swap(arr[start], arr[left]);
    return left;
} 

