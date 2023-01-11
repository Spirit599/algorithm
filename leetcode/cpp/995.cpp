class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {

        int n = nums.size();
        int diff[n + 1];
        memset(diff, 0, sizeof(diff));
        int ans = 0;

        int cnt = 0;
        for(int i = 0; i < n; ++i)
        {
            cnt += diff[i];
            if((cnt + nums[i]) % 2 == 0)
            {
                if(i + k > n)
                    return -1;
                ++diff[i + 1];
                --diff[i + k];
                ++ans;
            }
        }

        return ans;
    }
};