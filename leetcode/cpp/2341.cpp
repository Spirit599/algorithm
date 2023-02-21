class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        
        int ans = 0;
        int left = 0;
        unordered_map<int, int> memo;
        for(int num : nums)
            ++memo[num];
        for(auto [k, v] : memo)
        {
            ans += v / 2;
            left += v % 2;
        }
        return {ans, left};
    }
};