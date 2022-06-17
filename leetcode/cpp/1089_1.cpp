//1089. 复写零

class Solution {
public:
    void duplicateZeros(vector<int>& arr) {

        int fast = 0;
        int n = arr.size();
        int i = 0;
        while(fast < n)
        {
            if(arr[i] == 0)
                fast += 2;
            else
                ++fast;
            ++i;
        }
        --i;

        int end = n - 1;
        if(fast == n + 1)
        {
            arr[end] = 0;
            --end;
            --i;
        }

        while(end >= 0)
        {
            if(arr[i] == 0)
            {
                arr[end--] = 0;
                arr[end--] = 0;
                --i; 
            }
            else
            {
                arr[end--] = arr[i--];
            }
        }
    }
};