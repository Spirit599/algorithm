// 2406. 将区间分为最少组数

class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        
        map<int, int> diff;
        for(auto& vec : intervals)
        {
            ++diff[vec[0]];
            --diff[vec[1] + 1];
        }

        int sum = 0;
        int ans = 0;
        for(auto &[_, v] : diff)
        {
            sum += v;
            ans = max(ans, sum);
        }

        return ans;

    }
};