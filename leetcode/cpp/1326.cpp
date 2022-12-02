class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {

        vector<pair<int, int>> vpii;
        for(int i = 0; i <= n; ++i)
        {
            if(ranges[i] != 0)
            {
                vpii.emplace_back(i - ranges[i], i + ranges[i]);
            }
        }

        sort(vpii.begin(), vpii.end());

        int start = 0;
        int end = 0;
        int m = vpii.size();
        int ans = 0;
        for(int i = 0; i < m; ++i)
        {
            auto [x, y] = vpii[i];
            if(x <= start)
            {
                end = max(end, y);
            }
            else if(x <= end)
            {
                if(y > end)
                {
                    ++ans;
                    start = end;
                    end = max(end, y);
                }
            }
            else
            {
                break;
            }
            if(end >= n)
                break;
        }

        if(end < n)
            return -1;
        else
            return ans + 1;
    }
};