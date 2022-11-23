class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {

        unordered_map<int, int> memo;
        memo[0] = 1;

        int pre = 0;
        int n = nums.size();
        int ans = 0;
        for(int i = 0; i < n; ++i)
        {
            pre = (((pre + nums[i]) % k) + k) % k;

            auto it = memo.find(pre);
            if(it != memo.end())
            {
                ans += it->second;
                ++(it->second);
            }
            else
            {
                memo[pre] = 1;
            }
            printf("%d\n", ans);
        }
        return ans;
    }
};