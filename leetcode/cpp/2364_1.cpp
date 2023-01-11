// 2364. 统计坏数对的数目

class Solution {
public:
    long long countBadPairs(vector<int>& nums) {

        long long n = nums.size();
        long long ans = n * (n - 1) / 2;
        unordered_map<int, int> memo;
        for(int i = 0; i < n; ++i) {
            auto it = memo.find(nums[i] - i);
            if(it != memo.end())
            {
                ans -= it->second;
                ++(it->second);
            }
            else
                memo[nums[i] - i] = 1;
        }

        return ans;
    }
};