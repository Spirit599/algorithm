// 2406. 将区间分为最少组数

class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        
        vector<pair<int, int>> things;
        for(auto& vec : intervals)
        {
            things.push_back({vec[0], -1});
            things.push_back({vec[1], 1});

        }

        int ans = 0;
        int cur = 0;
        sort(things.begin(), things.end());

        for(auto& thing : things)
        {
            cur += (-1) * thing.second;
            ans = max(ans, cur);
        }

        return ans;

    }
};