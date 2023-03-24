typedef pair<int, int>  pii;

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {

        int n = nums.size();
        vector<int> ret(n);
        vector<pii> arr(n);
        for(int i = 0; i < n; ++i)
            arr[i] = make_pair(nums[i], i);
        vector<pii> tmp(n);

        function<void(int, int)> mergeSort = [&](int start, int end) -> void {

            if(start == end)
                return ;
            
            int mid = (start + end) >> 1;
            mergeSort(start, mid);
            mergeSort(mid + 1, end);

            int ll = start;
            int rr = mid + 1;
            int ptr = start;

            while(ll <= mid && rr <= end)
            {
                auto [llval, llidx] = arr[ll];
                auto [rrval, rridx] = arr[rr];
                if(llval <= rrval)
                {
                    tmp[ptr++] = arr[ll++];
                    ret[llidx] += (rr - mid - 1);
                }
                else
                {
                    tmp[ptr++] = arr[rr++];
                }
            }
            while(ll <= mid)
            {
                auto [llval, llidx] = arr[ll];
                ret[llidx] += (rr - mid - 1);
                tmp[ptr++] = arr[ll++];
            }
            while(rr <= end)
            {
                tmp[ptr++] = arr[rr++];
            }
            for(int i = start; i <= end; ++i)
                arr[i] = tmp[i];
            

        };

        mergeSort(0, n - 1);


        return ret;
    }
};