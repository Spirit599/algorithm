class Solution {
public:
    struct info
    {
        int start;
        int end;
        int cost;
    };
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {

        int inf = INT_MAX;
        int n = startTime.size();
        vector<info> workInfo(n);
        for(int i = 0; i < n; ++i)
            workInfo[i] = {startTime[i], endTime[i], profit[i]};

        sort(workInfo.begin(), workInfo.end(), [](const info& p1, const info& p2)
            {return p1.end < p2.end;});

        vector<pair<int, int>> dp;
        dp.emplace_back(workInfo[0].end, workInfo[0].cost);
        for(int i = 1; i < n; ++i)
        {
            int preMax = 0;
            auto it = upper_bound(dp.begin(), dp.end(), make_pair(workInfo[i].start, inf));
            if(it != dp.begin())
                preMax = (--it)->second;
            dp.emplace_back(workInfo[i].end, max(preMax + workInfo[i].cost, dp.back().second));
        }

        return dp.back().second;
    }
};