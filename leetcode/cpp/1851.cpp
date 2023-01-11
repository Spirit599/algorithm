typedef pair<int, int> pii;

class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {

        int querySize = queries.size();
        vector<pii> queryWithIdx(querySize);
        for(int i = 0; i < querySize; ++i)
            queryWithIdx[i] = make_pair(queries[i], i);
        sort(queryWithIdx.begin(), queryWithIdx.end());
        sort(intervals.begin(), intervals.end());

        auto cmp = [](const pii& p1, const pii& p2) {

            return p1.second - p1.first > p2.second - p2.first;
        };

        priority_queue<pii, vector<pii>, decltype(cmp)> pq(cmp);

        vector<int> ans(querySize);
        int n = intervals.size();
        int idx = 0;
        for(int i = 0; i < querySize; ++i)
        {
            auto [val, qIdx] = queryWithIdx[i];
            while(idx < n && intervals[idx][0] <= val)
            {
                pq.emplace(intervals[idx][0], intervals[idx][1]);
                ++idx;
            }
            while(!pq.empty() && pq.top().second < val)
            {
                pq.pop();
            }
            if(!pq.empty())
            {
                ans[qIdx] = pq.top().second - pq.top().first + 1;
            }
            else
                ans[qIdx] = -1;
        }

        return ans;
    }
};