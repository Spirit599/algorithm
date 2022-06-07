#include<iostream>
#include<vector>
#include<time.h>

using namespace std;

void modify_heap(vector<int>& nums, int index, int len)
{
    while( (index << 1) + 1 <= len )
    {
        int left_son = (index << 1) + 1;
        int right_son = (index << 1) + 2;
        int maxx_index = index;

        if(left_son <= len && nums[maxx_index] < nums[left_son])
        {
            maxx_index = left_son;
        }
        if(right_son <= len && nums[maxx_index] < nums[right_son])
        {
            maxx_index = right_son;
        }

        if(maxx_index != index)
        {
            swap(nums[maxx_index], nums[index]);
            index = maxx_index;
        }
        else
        {
            break;
        }
    }
}


void build_heap(vector<int>& nums, int len)
{
    for(int i = len / 2; i >= 0; --i)
    {
        modify_heap(nums, i, len);
    }
}

void sort_heap(vector<int>& nums)
{
    int len = nums.size() - 1;
    build_heap(nums, len);

    for(int i = len; i >= 1; --i)
    {
        swap(nums[len], nums[0]);
        --len;
        modify_heap(nums, 0, len);
    }
}




int main(int argc, char const *argv[])
{
    srand((unsigned)time(NULL));
    vector<int> nums;
    for(int i = 0; i <= 11; ++i)
        nums.emplace_back(rand() % 100);
    for(int num : nums)
        cout<<num<<' ';
    cout<<endl;

    sort_heap(nums);

    for(int num : nums)
        cout<<num<<' ';
    cout<<endl;


    return 0;
}