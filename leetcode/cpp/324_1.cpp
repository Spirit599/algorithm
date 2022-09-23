// 324. 摆动排序 II
// to be improve

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        
        vector<int> arr(nums);
        sort(arr.begin(), arr.end());

        int n = nums.size();
        int cnt = n >> 1;
        bool odd = n & 1;
        int p1 = cnt - 1;
        int p2 = n - 1;
        if(odd)
        {
            nums.back() = arr[0];
            ++p1;
        }
        int i = 0;
        int j = 1;
        while(cnt--)
        {
            nums[i] = arr[p1];
            nums[j] = arr[p2];
            i = i + 2;
            j = j + 2;
            --p1;
            --p2;
        }

    }
};