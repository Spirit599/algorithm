class Solution {
public:
    int countTriplets(vector<int>& nums) {

        int S = 1 << 16;
        int maskCnt[S];
        memset(maskCnt, 0, sizeof(maskCnt));
        for(int num : nums)
        {
            for(int mask = 0; mask < S; ++mask)
            {
                if((num | mask) == num + mask)
                {
                    ++maskCnt[mask];
                }
            }
        }

        int ans = 0;
        int n = nums.size();
        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                int num = nums[i] & nums[j];
                ans += maskCnt[num];

            }
        }

        return ans;
    }
};