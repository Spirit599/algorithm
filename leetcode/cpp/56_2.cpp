//珂朵莉

typedef pair<int, int> pii;
class Solution {
public:
    set<pii> memo;

    void add(int ll, int rr) {

        auto it = memo.lower_bound(make_pair(ll, INT_MIN));
        while(it != memo.end())
        {
            int nll = it->second;
            int nrr = it->first;
            if(nll > rr)
                break;
            ll = min(ll, nll);
            rr = max(rr, nrr);
            memo.erase(it++);
        }
        memo.emplace(rr, ll);
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        for(auto& interval : intervals)
        {
            add(interval[0], interval[1]);
        }

        vector<vector<int>> ans;
        for(auto& k : memo)
        {
            ans.push_back({k.second, k.first});
        }
        return ans;
    }
};