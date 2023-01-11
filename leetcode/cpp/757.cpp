class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {

        sort(intervals.begin(), intervals.end());
        int ans = 0;
        int a = -1;
        int b = -1;
        int n = intervals.size();

        for(int i = 0; i < n; ++i)
        {
            if(intervals[i][0] > b)
            {
                ans += 2;
                a = intervals[i][0];
                b = intervals[i][1];
            }
            else if(intervals[i][0] == b)
            {
                ans += 1;
                a = intervals[i][0];
                b = intervals[i][1];
            }
            else
            {
                a = intervals[i][0];
                b = max(b, intervals[i][1]);
            }
        }

        return ans;
    }
};