class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        sort(intervals.begin(), intervals.end());

        int curIndex = 0;
        int n = intervals.size();
        for(int i = 1; i < n; ++i)
        {
            if(intervals[i][0] <= intervals[curIndex][1])
            {
                int left = min(intervals[i][0], intervals[curIndex][0]);
                int right = max(intervals[i][1], intervals[curIndex][1]);
                intervals[curIndex][0] = left;
                intervals[curIndex][1] = right;   
            }
            else
            {
                ++curIndex;
                intervals[curIndex][0] = intervals[i][0];
                intervals[curIndex][1] = intervals[i][1];
            }
        }

        return vector<vector<int>>(intervals.begin(), intervals.begin() + curIndex + 1);
    }
};