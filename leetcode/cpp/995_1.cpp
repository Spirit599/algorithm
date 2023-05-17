class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {

        int n = nums.size();
        int diff[n + 1];
        memset(diff, 0, sizeof(diff));

        int ans = 0;
        int cur = 0;

        for(int i = 0; i < n; ++i)
        {
            cur = diff[i] + nums[i];
            if((cur & 1) == 0)
            {
                printf("%d\n", i);
                if(i + k > n)
                    return -1;
                diff[i + 1] += 1;
                diff[i + k] -= 1;
                ++ans;
            }
        }

        return ans;
    }
};