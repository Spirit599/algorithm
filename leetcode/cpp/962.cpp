class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {

        int n = nums.size();
        
        int index[n];
        for(int i = 0; i < n; ++i)
            index[i] = i;

        sort(index, index + n, [&](int a, int b)
            {
                if(nums[a] != nums[b])
                    return nums[a] < nums[b];
                else
                    return a < b;
            });

        int ans = 0;
        int minn = n;
        for(int i = 0; i < n; ++i)
        {
            ans = max(ans, index[i] - minn);
            minn = min(minn, index[i]);
        }
        return ans;

    }
};