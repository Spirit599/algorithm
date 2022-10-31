class Solution {
public:
    int destroyTargets(vector<int>& nums, int space) {
        
        vector<int> arr = nums;
        unordered_map<int, int> memo;

        for(int& num : arr)
        {
            num = num % space;
            ++memo[num];
        }

        int n = arr.size();
        for(int i = 0; i < n; ++i)
            arr[i] = memo[arr[i]];

        int ans = INT_MAX;
        int maxx = 0;
        for(int i = 0; i < n; ++i)
        {
            if(arr[i] > maxx)
            {
                maxx = arr[i];
                ans = nums[i];
            }
            else if(arr[i] == maxx)
            {
                ans = min(ans, nums[i]);
            }
        }

        return ans;
        

    }
};