class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {

        unordered_map<int, int> memo;
        memo[0] = -1;
        int preSum = 0;
        int n = nums.size();

        for(int i = 0; i < n; ++i)
        {
            preSum += nums[i];
            int key = preSum % k;
            auto it = memo.find(key);
            if(it == memo.end())
            {
                memo[key] = i;
            }
            else
            {
                if(i - it->second >= 2)
                    return true;
            }
        }
        return false;
    }
};