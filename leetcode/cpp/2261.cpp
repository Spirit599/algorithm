class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        
        unordered_set<string> memo;
        int n = nums.size();
        for(int i = 0; i < n; ++i)
        {
            string cur;
            int cnt = 0;
            for(int j = i; j < n; ++j)
            {
                if(nums[j] % p == 0)
                    ++cnt;
                if(cnt > k)
                    break;

                cur += to_string(nums[j]);
                cur.push_back('#');
                memo.insert(cur);
            }
        }
        
        return memo.size();
    }
};