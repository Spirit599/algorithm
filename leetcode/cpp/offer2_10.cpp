class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {

        int sum = 0;
        for(int& num : nums)
        {
            sum += num;
            num = sum;
        }

        unordered_map<int, int> memo;
        memo[0] = 1;
        int ans = 0;
        for(int num : nums)
        {
            auto it = memo.find(num - k);
            if(it != memo.end())
                ans += it->second;
            ++memo[num];
        }
        return ans;
    }
};