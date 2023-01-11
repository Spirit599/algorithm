class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {

        int n = nums.size();
        if(n < 3)
            return false;

        int minn[n];
        memset(minn, 0x3f, sizeof(minn));
        minn[0] = nums[0];
        int maxx[n];
        memset(maxx, 0, sizeof(maxx));
        maxx[n - 1] = nums[n - 1];

        for(int i = 1; i < n; ++i)
            minn[i] = min(minn[i - 1], nums[i]);
        for(int i = n - 2; i >= 0; --i)
            maxx[i] = max(maxx[i + 1], nums[i]);

        for(int i = 1; i <= n - 2; ++i)
        {
            if(minn[i] < nums[i] && nums[i] < maxx[i])
                return true;
        }



        return false;
    }
};