// 560. 和为 K 的子数组
// 前缀和 + hash
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {

        unordered_map<int, int> memo;
        memo[0] = 1;

        int presum = 0;
        int ans = 0;
        for(int num : nums)
        {
            presum += num;
            auto it = memo.find(presum - k);
            if(it != memo.end())
                ans += it->second;
            ++memo[presum];
        }

        return ans;

    }
};