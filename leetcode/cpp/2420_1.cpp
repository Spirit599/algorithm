// 2420. 找到所有好下标

class Solution {
public:
    vector<int> goodIndices(vector<int>& nums, int k) {
        
        vector<int> ans;

        int n = nums.size();

        int left[n];
        memset(left, 0, sizeof(left));
        int cnt = 1;
        for(int i = 1; i < n; ++i)
        {
            left[i] = cnt;
            if(nums[i - 1] >= nums[i])
                ++cnt;
            else
                cnt = 1;
        }

        int right[n];
        memset(right, 0, sizeof(right));
        cnt = 1;
        for(int i = n - 2; i >= 0; --i)
        {
            right[i] = cnt;
            if(nums[i + 1] >= nums[i])
                ++cnt;
            else
                cnt = 1;
        }

        int i = k;
        while(i + k < n)
        {
            if(left[i] >= k && right[i] >= k)
                ans.push_back(i);
            i++;
        }

        return ans;

    }
};