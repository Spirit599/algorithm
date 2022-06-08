void quick_sort(vector<int>& arr, int k, int start, int end)
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

vector<int> quick_choose(vector<int>& arr, int k, int start, int end)
{
    int left = start;
    int right = end;
    while(left < right)
    {
        while(left < right && arr[right] >= arr[start])
            --right;
        while(left < right && arr[left] <= arr[start])
            ++left;
        swap(arr[left], arr[right]);
    }
    swap(arr[left], arr[start]);
    if(left > k)
        return quick_choose(arr, k, start, left - 1);
    else if(left < k)
        return quick_choose(arr, k, left + 1, end);
    return {arr.begin(), arr.begin() + k};
}