// 128.最长连续序列

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        int n = nums.size();
        if(n == 0)
            return 0;

        sort(nums.begin(), nums.end());
        int ans = 1;
        int cl = 1;
        int pri = nums[0];
        for(int i = 1; i < n; ++i)
        {
            if(nums[i] == nums[i - 1] + 1)
                ++cl;
            else if(nums[i] != nums[i - 1])
                cl = 1;
            else
                continue;
            ans = max(ans, cl);
        }



        return ans;
    }
};