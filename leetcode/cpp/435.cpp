class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {

        sort(intervals.begin(), intervals.end());
        int ans = 0;
        int right = -0x3f3f3f3f;
        int n = intervals.size();
        
        for(auto& interval : intervals)
        {
            if(interval[0] >= right) // 无冲突
            {
                right = interval[1];
            }
            else // 有冲突
            {
                ++ans;
                right = min(right, interval[1]);
            }
        }
        return ans;
    }
};