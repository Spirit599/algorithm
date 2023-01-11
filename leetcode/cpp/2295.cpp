class Solution {
public:
    vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& operations) {
        
        unordered_map<int, int> memo;
        int n = nums.size();
        for(int i = 0; i < n; ++i)
            memo[nums[i]] = i;

        for(auto& oper : operations)
        {
            int key = oper[0];
            auto it = memo.find(key);
            int index = it->second;

            memo.erase(it);
            nums[index] = oper[1];
            memo[oper[1]] = index;

        }
        return nums;
    }
};