// 581. 最短无序连续子数组

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {

        int n = nums.size();
        if(n == 1)
            return 0;

        int minn[n];
        memset(minn, 0x3f, sizeof(minn));
        int maxx[n];
        memset(maxx, 0, sizeof(maxx));

        maxx[0] = nums[0];
        for(int i = 1; i < n; ++i)
            maxx[i] = max(maxx[i - 1], nums[i]);

        int right = 0;
        for(int i = n - 1; i >= 0; --i)
        {
            if(maxx[i] > nums[i])
            {
                right = i;
                break;
            }
        }

        minn[n - 1] = nums[n - 1];
        for(int i = n - 2; i >= 0; --i)
            minn[i] = min(minn[i + 1], nums[i]);
        
        int left = n - 1;
        for(int i = 0; i < n; ++i)
        {
            if(minn[i] < nums[i])
            {
                left = i;
                break;
            }
        }

        return max(right - left + 1, 0);

    }
};