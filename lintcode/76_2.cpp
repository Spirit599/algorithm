class Solution {
public:
    /**
     * @param nums: An integer array
     * @return: The length of LIS (longest increasing subsequence)
     */
    int longestIncreasingSubsequence(vector<int> &nums) {
        
        int n = nums.size();
        int up[n];
        int up_cnt = 0;
        int ans = 0;

        for(int num : nums)
        {
            int k = binary_search(up, 0, up_cnt, num);
            ans = max(ans, k);
            up_cnt = ans;
            for(int i = 0; i < up_cnt; ++i)
                cout<<up[i]<<" ";
            cout<<endl;
        }


        return ans;
    }



    int binary_search(int up[], int low, int high, int target)
    {
        if(high == 0)
        {
            up[0] = target;
            return 1;
        }

        int n = high - 1;
        --high;

        while(low < high)
        {
            int mid = low + (high - low) / 2;
            if(target <= up[mid])
                high = mid;
            else
                low = mid + 1;
        }
        cout<<low<<endl;

        if(low == n)
        {
            if(target <= up[n])
            {
                up[n] = target;
                return n + 1;
            }
            else
            {
                up[n + 1] = target;
                return n + 2;
            }
        }
        else
        {
            up[low] = target;
            return low + 1;
        }
    }
};