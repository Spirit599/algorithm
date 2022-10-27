class Solution {
public:
    vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& operations) {
        
        unordered_map<int, int> memo;
        int n = operations.size();
        for(int i = n - 1; i >= 0; --i)
        {
            auto& vec = operations[i];
            auto it = memo.find(vec[1]);
            if(it == memo.end())
            {
                memo[vec[0]] = vec[1];
            }
            else
            {
                memo[vec[0]] = it->second;
            }
        }
        for(int& num : nums)
        {
            auto it = memo.find(num);
            if(it != memo.end())
            {
                num = memo[num];
            }
        }
        return nums;
    }
};