class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {

        int n = intervals.size();
        for(int i = 0; i < n; ++i)
        {
            intervals[i].push_back(i);
        }
        sort(intervals.begin(), intervals.end());

        function<int(int)> findStart = [&](int right) -> int {

            int low = 0;
            int high = n;
            while(low != high)
            {
                int mid = (low + high) >> 1;
                if(intervals[mid][0] >= right)
                {
                    high = mid;
                }
                else
                {
                    low = mid + 1;
                }
            } 
            if(low != n)
                return intervals[low][2];
            else
                return -1;
        };
        vector<int> ans(n);
        for(int i = 0; i < n; ++i)
        {
            int right = intervals[i][1];
            ans[intervals[i][2]] = findStart(right);
        }
        return ans;
    }
};