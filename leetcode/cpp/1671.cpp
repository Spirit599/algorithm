class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {

        int n = nums.size();
        int left[n];
        memset(left, 0, sizeof(left));

        vector<int> upVec;
        for(int i = 0; i < n; ++i)
        {
            int val = nums[i];
            auto it = lower_bound(upVec.begin(), upVec.end(), val);
            if(it == upVec.end())
            {
                upVec.emplace_back(val);
                left[i] = upVec.size();
            }
            else
            {
                *it = val;
                left[i] = it - upVec.begin() + 1;
            }
        }

        upVec.clear();
        int ans = INT_MAX;
        for(int i = n - 1; i >= 0; --i)
        {
            int val = nums[i];
            auto it = lower_bound(upVec.begin(), upVec.end(), val);
            int righti;
            if(it == upVec.end())
            {
                upVec.emplace_back(val);
                righti = upVec.size();
            }
            else
            {
                *it = val;
                righti = it - upVec.begin() + 1;
            }
            if(left[i] == 1 || righti == 1)
                continue;
            ans = min(ans, n - left[i] - righti + 1);
        }

        return ans;


    }
};