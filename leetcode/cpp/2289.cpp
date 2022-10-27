// 单调栈
// hard

class Solution {
public:
    int totalSteps(vector<int>& nums) {
        
        stack<pair<int, int>> sta;

        int ans = 0;
        int n = nums.size();
        for(int i = 0; i < n; ++i)
        {
            int maxx = 0;
            while(!sta.empty() && nums[sta.top().first] <= nums[i])
            {
                maxx = max(maxx, sta.top().second);
                sta.pop();
            }
            if(!sta.empty())
            {
                ans = max(ans, maxx + 1);
            }
            sta.push(make_pair(i, maxx + 1));
        }

        return ans;
    }
};