// 128.最长连续序列

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        unordered_set<int> memo(nums.begin(), nums.end());
        // for(int num : nums)
        //     memo.insert(num);

        int ans = 0;

        for(int num : memo)
        {
            if(memo.count(num - 1))
                continue;

            int cur_key = num;
            int cur_length = 1;

            while(memo.count(cur_key + 1))
            {
                ++cur_key;
                ++cur_length;
            }

            ans = max(ans, cur_length);
        }

        return ans;
    }
};