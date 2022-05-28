class Solution {
    unordered_map<int, vector<int>> memo;
public:
    Solution(vector<int>& nums) {

        

        int n = nums.size();
        for(int i = 0; i < n; ++i)
        {
            memo[nums[i]].emplace_back(i);
        }
    }
    
    int pick(int target) {

        auto it = memo.find(target);
        if(it != memo.end())
        {
            vector<int>& cur = it->second;

            int rand_index = rand() % cur.size();
            return cur[rand_index];
        }
        else
        {
            return -1;
        }
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */