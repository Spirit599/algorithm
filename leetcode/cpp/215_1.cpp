//215 TopK
//快速选择
#include<iostream>
#include<algorithm>
#include<cstdlib>
#include<time.h>
#include<vector>
using namespace std;


class Solution {
public:
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
};

class Solution1 {
public:
    int findKthLargest(vector<int>& nums, int k) 
    {
        sort(nums.begin(), nums.end(), greater<int>());
        return nums[k - 1];
    }
};

int main(int argc, char const *argv[])
{
    srand((unsigned)time(NULL));
    vector<int> arr;
    int n = 10000000;
    for(int i = 0; i < n; ++i)
        arr.push_back(rand());
    vector<int> arr1(arr);
    
    time_t t1 = time(NULL);
    cout<<Solution1().findKthLargest(arr1, n / 2)<<endl;
    time_t t2 = time(NULL);
    cout<<t2 - t1<<endl;
    cout<<Solution().findKthLargest(arr, n / 2)<<endl;
    time_t t3 = time(NULL);
    cout<<t3 - t2<<endl;
    sort(arr.begin(), arr.end());
    cout<<Solution1().findKthLargest(arr, n / 2)<<endl;
    time_t t4 = time(NULL);
    cout<<t4 - t3<<endl;

    return 0;
}