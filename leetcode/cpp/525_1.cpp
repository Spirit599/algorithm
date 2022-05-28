//前缀和
//hash

class Solution {
public:
    int findMaxLength(vector<int>& nums) {

        int ans = 0;
        unordered_map<int, int> um;
        int cur = 0;
        um[cur] = -1;

        for(int i = 0; i < nums.size(); ++i)
        {
            if(nums[i] == 0)
                --cur;
            else
                ++cur;

            if(um.count(cur))
                ans = max(ans, i - um[cur]);
            else
                um[cur] = i;
        }

        return ans;
    }
};